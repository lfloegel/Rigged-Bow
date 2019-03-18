//==============================================================================
/*
    Software License Agreement (BSD License)
    Copyright (c) 2003-2016, CHAI3D.
    (www.chai3d.org)

    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above
    copyright notice, this list of conditions and the following
    disclaimer in the documentation and/or other materials provided
    with the distribution.

    * Neither the name of CHAI3D nor the names of its contributors may
    be used to endorse or promote products derived from this software
    without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
    FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
    COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
    ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE. 

    \author    <http://www.chai3d.org>
    \author    Francois Conti
    \version   $MAJOR.$MINOR.$RELEASE $Rev: 1925 $
*/
//==============================================================================

//------------------------------------------------------------------------------
#include "chai3d.h"
//------------------------------------------------------------------------------
#include <GLFW/glfw3.h>
//------------------------------------------------------------------------------
using namespace chai3d;
using namespace std;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// GENERAL SETTINGS
//------------------------------------------------------------------------------

// stereo Mode
/*
    C_STEREO_DISABLED:            Stereo is disabled 
    C_STEREO_ACTIVE:              Active stereo for OpenGL NVDIA QUADRO cards
    C_STEREO_PASSIVE_LEFT_RIGHT:  Passive stereo where L/R images are rendered next to each other
    C_STEREO_PASSIVE_TOP_BOTTOM:  Passive stereo where L/R images are rendered above each other
*/
cStereoMode stereoMode = C_STEREO_DISABLED;

// fullscreen mode
bool fullscreen = false;

// mirrored display
bool mirroredDisplay = false;


//------------------------------------------------------------------------------
// DECLARED VARIABLES
//------------------------------------------------------------------------------

// a world that contains all objects of the virtual environment
cWorld* world;

// a camera to render the world in the window display
cCamera* camera;

// a light source to illuminate the objects in the world
cDirectionalLight *light;

// a haptic device handler
cHapticDeviceHandler* handler;

// a pointer to the current haptic device
cGenericHapticDevicePtr hapticDevice;

// a virtual tool representing the haptic device in the scene
cToolCursor* tool;

// a few objects that are placed in the scene
//cMesh* cylinder;
cMultiMesh* bow;
cMultiMesh* pig;
cMultiMesh* pig2;
cMultiMesh* pig3;
cMultiMesh* arrow;
cMultiMesh* object;

cShapeLine* top;

double displacement;
cVector3d init_pos;

cShapeLine* bottom;

// a colored background
cBackground* background;

// rendering option
bool showTexture = true;

// a font for rendering text
cFontPtr font;

// a label to display the rate [Hz] at which the simulation is running
//cLabel* labelRates;
cLabel* labelMessage;

// a flag that indicates if the haptic simulation is currently running
bool simulationRunning = false;

// a flag that indicates if the haptic simulation has terminated
bool simulationFinished = true;

// a frequency counter to measure the simulation graphic rate
cFrequencyCounter freqCounterGraphics;

// a frequency counter to measure the simulation haptic rate
cFrequencyCounter freqCounterHaptics;

// haptic thread
cThread* hapticsThread;

// a handle to window display context
GLFWwindow* window = NULL;

// a flag for using damping (ON/OFF)
bool useDamping = false;

// a flag for using force field (ON/OFF)
bool useForceField = true;

// current width of window
int width = 0;

bool isPull = false;

// current height of window
int height = 0;

// swap interval for the display context (vertical synchronization)
int swapInterval = 1;

// root resource path
string resourceRoot;


//------------------------------------------------------------------------------
// DECLARED FUNCTIONS
//------------------------------------------------------------------------------

// callback when the window display is resized
void windowSizeCallback(GLFWwindow* a_window, int a_width, int a_height);

// callback when an error GLFW occurs
void errorCallback(int error, const char* a_description);

// callback when a key is pressed
void keyCallback(GLFWwindow* a_window, int a_key, int a_scancode, int a_action, int a_mods);

// this function renders the scene
void updateGraphics(void);

// this function contains the main haptics simulation loop
void updateHaptics(void);

// this function closes the application
void close(void);

#define RESOURCE_PATH(p)    (char*)((resourceRoot+string(p)).c_str())


//==============================================================================
/*
    DEMO:   13-primitives.cpp

    This example illustrates how to build simple triangle based mesh primitives 
    using the functions provided in file graphics/CPrimitives.h
*/
//==============================================================================

int main(int argc, char* argv[])
{
    //--------------------------------------------------------------------------
    // INITIALIZATION
    //--------------------------------------------------------------------------

    cout << endl;
    cout << "-----------------------------------" << endl;
    cout << "CHAI3D" << endl;
    cout << "Demo: 13-primitives" << endl;
    cout << "Copyright 2003-2016" << endl;
    cout << "-----------------------------------" << endl << endl << endl;
    cout << "Keyboard Options:" << endl << endl;
    cout << "[s] - Save copy of shadowmap to file" << endl;
    cout << "[f] - Enable/Disable full screen mode" << endl;
    cout << "[m] - Enable/Disable vertical mirroring" << endl;
    cout << "[q] - Exit application" << endl;
    cout << endl << endl;


    //--------------------------------------------------------------------------
    // OPEN GL - WINDOW DISPLAY
    //--------------------------------------------------------------------------

    // initialize GLFW library
    if (!glfwInit())
    {
        cout << "failed initialization" << endl;
        cSleepMs(1000);
        return 1;
    }

    // set error callback
    glfwSetErrorCallback(errorCallback);

    // compute desired size of window
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    int w = 0.8 * mode->height;
    int h = 0.5 * mode->height;
    int x = 0.5 * (mode->width - w);
    int y = 0.5 * (mode->height - h);

    // set OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    // set active stereo mode
    if (stereoMode == C_STEREO_ACTIVE)
    {
        glfwWindowHint(GLFW_STEREO, GL_TRUE);
    }
    else
    {
        glfwWindowHint(GLFW_STEREO, GL_FALSE);
    }

    // create display context
    window = glfwCreateWindow(w, h, "CHAI3D", NULL, NULL);
    if (!window)
    {
        cout << "failed to create window" << endl;
        cSleepMs(1000);
        glfwTerminate();
        return 1;
    }

    // get width and height of window
    glfwGetWindowSize(window, &width, &height);

    // set position of window
    glfwSetWindowPos(window, x, y);

    // set key callback
    glfwSetKeyCallback(window, keyCallback);

    // set resize callback
    glfwSetWindowSizeCallback(window, windowSizeCallback);

    // set current display context
    glfwMakeContextCurrent(window);

    // sets the swap interval for the current display context
    glfwSwapInterval(swapInterval);

#ifdef GLEW_VERSION
    // initialize GLEW library
    if (glewInit() != GLEW_OK)
    {
        cout << "failed to initialize GLEW library" << endl;
        glfwTerminate();
        return 1;
    }
#endif


    //--------------------------------------------------------------------------
    // WORLD - CAMERA - LIGHTING
    //--------------------------------------------------------------------------

    // create a new world.
    world = new cWorld();

    // set the background color of the environment
    world->m_backgroundColor.setBlack();

    // create a camera and insert it into the virtual world
    camera = new cCamera(world);
    world->addChild(camera);

    // position and orient the camera
    camera->set(cVector3d(0.9, 0.0, 0.6),    // camera position (eye)
                cVector3d(0.0, 0.0, 0.0),    // lookat position (target)
                cVector3d(0.0, 0.0, 1.0));   // direction of the (up) vector

    // set the near and far clipping planes of the camera
    // anything in front or behind these clipping planes will not be rendered
    camera->setClippingPlanes(0.01, 10.0);

    // set stereo mode
    camera->setStereoMode(stereoMode);

    // set stereo eye separation and focal length (applies only if stereo is enabled)
    camera->setStereoEyeSeparation(0.03);
    camera->setStereoFocalLength(1.8);

    // set vertical mirrored display mode
    camera->setMirrorVertical(mirroredDisplay);

    // create a light source
    light = new cDirectionalLight(world);
    
    // attach light to camera
    camera->addChild(light);
    
    // enable light source
    light->setEnabled(true);
    
    // define the direction of the light beam
    light->setDir(-3.0,-0.5, 0.0);
    
    // set lighting conditions
    light->m_ambient.set(0.4f, 0.4f, 0.4f);
    light->m_diffuse.set(0.8f, 0.8f, 0.8f);
    light->m_specular.set(0.1f, 0.2f, 0.1f);

    //--------------------------------------------------------------------------
    // HAPTIC DEVICES / TOOLS
    //--------------------------------------------------------------------------

    // create a haptic device handler
    handler = new cHapticDeviceHandler();

    // get access to the first available haptic device
    handler->getDevice(hapticDevice, 0);

    // retrieve information about the current haptic device
    cHapticDeviceInfo hapticDeviceInfo = hapticDevice->getSpecifications();

    // if the haptic devices carries a gripper, enable it to behave like a user switch
    hapticDevice->setEnableGripperUserSwitch(true);

    // create a tool (cursor) and insert into the world
    tool = new cToolCursor(world);
    world->addChild(tool);

    
    top = new cShapeLine(cVector3d(.2,0,.4), cVector3d(0.0, 0.0, 0.0));
    world -> addChild(top);
    bottom = new cShapeLine(cVector3d(0.0, 0.0, 0.0), cVector3d(.2,0,-.4));
    world -> addChild(bottom);
    //adding bow string points

    // connect the haptic device to the tool
    tool->setHapticDevice(hapticDevice);

    // map the physical workspace of the haptic device to a larger virtual workspace.
    tool->setWorkspaceRadius(1.0);

    // define the radius of the tool (sphere)
    double toolRadius = 0.03;

    // define a radius for the tool
    tool->setRadius(toolRadius);

    // hide the device sphere. only show proxy.
    tool->setShowContactPoints(true, false);

    // enable if objects in the scene are going to rotate of translate
    // or possibly collide against the tool. If the environment
    // is entirely static, you can set this parameter to "false"
    tool->enableDynamicObjects(true);

    // haptic forces are enabled only if small forces are first sent to the device;
    // this mode avoids the force spike that occurs when the application starts when 
    // the tool is located inside an object for instance. 
    tool->setWaitForSmallForce(true);

    // start the haptic tool
    tool->start();


    //--------------------------------------------------------------------------
    // CREATE OBJECTS
    //--------------------------------------------------------------------------

    // read the scale factor between the physical workspace of the haptic
    // device and the virtual workspace defined for the tool
    double workspaceScaleFactor = tool->getWorkspaceScaleFactor();

    // stiffness properties
    double maxStiffness	= hapticDeviceInfo.m_maxLinearStiffness / workspaceScaleFactor;

    /////////////////////////////////////////////////////////////////////////
    // BOW
    /////////////////////////////////////////////////////////////////////////

    // create a virtual mesh
    bow = new cMultiMesh();
    
    // add object to world
    world->addChild(bow);
    
    // set the position of bow object at the center of the world
    bow->setLocalPos(0.0, 0.0, 0.0);
    bow->rotateAboutGlobalAxisDeg(cVector3d(1,0,0), 90);
    bow->rotateAboutGlobalAxisDeg(cVector3d(0,1,0), 180);
    
    // load an object file
    bool fileload;
    fileload = bow->loadFromFile(RESOURCE_PATH("../resources/models/turntable/bowa.obj"));
    if (!fileload)
    {
    #if defined(_MSVC)
        fileload = bow->loadFromFile("../../../bin/resources/models/turntable/bowa.obj");
    #endif
    }
    if (!fileload)
    {
        printf("Error - 3D Model failed to load correctly.\n");
        close();
        return (-1);
    }
    
    // compute a boundary box
    bow->computeBoundaryBox(true);
    
    // get dimensions of object
    double size = cSub(bow->getBoundaryMax(), bow->getBoundaryMin()).length();
    
    // resize object to screen
    if (size > 0)
    {
        bow->scale( 1.0 / size);
    }
    
    // setup collision detection algorithm
    bow->createAABBCollisionDetector(toolRadius);
    
    // define a default stiffness for the object
    bow->setStiffness(0.8 * maxStiffness, true);
    
    
    /////////////////////////////////////////////////////////////////////////
    // PIGS
    /////////////////////////////////////////////////////////////////////////
    
    // create a virtual mesh
    pig2 = new cMultiMesh();
    
    // add object to world
    world->addChild(pig2);
    
    // set the position of bow object at the center of the world
    pig2->setLocalPos(-5.0, 3, -3.3);
    pig2->rotateAboutGlobalAxisDeg(cVector3d(0,0,1), 90);
    pig2->rotateAboutGlobalAxisDeg(cVector3d(0,1,0), -10);
    
    // load an object file
    fileload = pig2->loadFromFile(RESOURCE_PATH("../resources/models/hubble/pig2.3ds"));
    if (!fileload)
    {
    #if defined(_MSVC)
        fileload = pig2->loadFromFile("../resources/models/hubble/pig2.3ds");
    #endif
    }
    if (!fileload)
    {
        printf("Error - 3D Model failed to load correctly.\n");
        close();
        return (-1);
    }
    
    // compute a boundary box
    pig2->computeBoundaryBox(true);
    
    // get dimensions of object
    double size3 = cSub(pig2->getBoundaryMax(), pig2->getBoundaryMin()).length();
    
    // resize object to screen
    if (size3 > 0)
    {
        pig2->scale( 1.0 / size3);
    }
    
    // setup collision detection algorithm
    pig2->createAABBCollisionDetector(toolRadius);
    
    // define a default stiffness for the object
    pig2->setStiffness(0.8 * maxStiffness, true);
    
    /////////////////////////////////////////////////////////////////////////
    // ARROW
    /////////////////////////////////////////////////////////////////////////
    
    // create a virtual mesh
    arrow = new cMultiMesh();
    
    // add object to world
    world->addChild(arrow);
    
    // set the position of bow object at the center of the world
    arrow->setLocalPos(3.0, 0.5, 0.0);
    arrow->rotateAboutGlobalAxisDeg(cVector3d(0,0,0), 90);
    //pig->rotateAboutGlobalAxisDeg(cVector3d(0,0,0), 180);
    
    // load an object file
    fileload = arrow->loadFromFile(RESOURCE_PATH("../resources/models/turntable/arrow.obj"));
    if (!fileload)
    {
    #if defined(_MSVC)
        fileload = arrow->loadFromFile("../../../bin/resources/models/turntable/arrow.obj");
    #endif
    }
    if (!fileload)
    {
        printf("Error - 3D Model failed to load correctly.\n");
        close();
        return (-1);
    }
    
    // compute a boundary box
    arrow->computeBoundaryBox(true);
    
    // get dimensions of object
    size3 = cSub(arrow->getBoundaryMax(), arrow->getBoundaryMin()).length();
    
    // resize object to screen
    if (size3 > 0)
    {
        arrow->scale( 1.0 / size3);
    }
    
    // setup collision detection algorithm
    arrow->createAABBCollisionDetector(toolRadius);
    
    arrow->setStiffness(0.8 * maxStiffness, true);
    
    //--------------------------------------------------------------------------
    // CREATE SHADERS
    //--------------------------------------------------------------------------

    // create program shader
    cShaderProgramPtr shaderProgram = cShaderProgram::create(C_SHADER_FONG_VERT, C_SHADER_FONG_FRAG);

    // set uniforms
    shaderProgram->setUniformi("uShadowMap", C_TU_SHADOWMAP);

    // assign shader to mesh objects in the world
    tool->setShaderProgram(shaderProgram);
    world->setShaderProgram(shaderProgram);
    bow->setShaderProgram(shaderProgram);
    //pig->setShaderProgram(shaderProgram);
    //pig2->setShaderProgram(shaderProgram);
    //pig3->setShaderProgram(shaderProgram);
    arrow->setShaderProgram(shaderProgram);


    //--------------------------------------------------------------------------
    // WIDGETS
    //--------------------------------------------------------------------------

    // create a font
    font = NEW_CFONTCALIBRI20();
    
    /*
    // create a label to display the haptic and graphic rate of the simulation
    labelRates = new cLabel(font);
    labelRates->m_fontColor.setBlack();
    camera->m_frontLayer->addChild(labelRates);
     */
    
    // create a small message
    labelMessage = new cLabel(font);
    labelMessage->m_fontColor.setBlack();
    labelMessage->setText("SCORE: 0");
    labelMessage->setFontScale(1.3);
    camera->m_frontLayer->addChild(labelMessage);

    // create a background
    cBackground* background = new cBackground();
    camera->m_backLayer->addChild(background);
    
    // set aspect ration of background image a constant
    background->setFixedAspectRatio(true);
    
    // load an object file
    bool fileload2;
    
    fileload2 = background->loadFromFile(RESOURCE_PATH("../resources/images/grass.jpg"));
    if (!fileload2)
    {
    #if defined(_MSVC)
        fileload2 = background->loadFromFile("../../../bin/resources/images/grass.jpg");
    #endif
    }
    if (!fileload2)
    {
        cout << "Error - Image failed to load correctly." << endl;
        close();
        return (-1);
    }


    //--------------------------------------------------------------------------
    // START SIMULATION
    //--------------------------------------------------------------------------

    // create a thread which starts the main haptics rendering loop
    hapticsThread = new cThread();
    hapticsThread->start(updateHaptics, CTHREAD_PRIORITY_HAPTICS);

    // setup callback when application exits
    atexit(close);


    //--------------------------------------------------------------------------
    // MAIN GRAPHIC LOOP
    //--------------------------------------------------------------------------

    // call window size callback at initialization
    windowSizeCallback(window, width, height);

    // main graphic loop
    while (!glfwWindowShouldClose(window))
    {
        // get width and height of window
        glfwGetWindowSize(window, &width, &height);

        // render graphics
        updateGraphics();

        // swap buffers
        glfwSwapBuffers(window);

        // process events
        glfwPollEvents();

        // signal frequency counter
        freqCounterGraphics.signal(1);
    }

    // close window
    glfwDestroyWindow(window);

    // terminate GLFW library
    glfwTerminate();

    // exit
    return (0);
}

//------------------------------------------------------------------------------

void windowSizeCallback(GLFWwindow* a_window, int a_width, int a_height)
{
    // update window size
    width = a_width;
    height = a_height;
}

//------------------------------------------------------------------------------

void errorCallback(int a_error, const char* a_description)
{
    cout << "Error: " << a_description << endl;
}

//------------------------------------------------------------------------------

void updateBowString() {
    
}

//---------

void keyCallback(GLFWwindow* a_window, int a_key, int a_scancode, int a_action, int a_mods)
{
    // filter calls that only include a key press
    if ((a_action != GLFW_PRESS) && (a_action != GLFW_REPEAT))
    {
        return;
    }

    // option - exit
    else if ((a_key == GLFW_KEY_ESCAPE) || (a_key == GLFW_KEY_Q))
    {
        glfwSetWindowShouldClose(a_window, GLFW_TRUE);
    }
    
    // option - show/hide texture
    if (a_key == GLFW_KEY_1)
    {
        showTexture = !showTexture;
        pig3->setUseTexture(showTexture);
    }

    // option - save shadow map to file
    else if (a_key == GLFW_KEY_S)
    {
        cImagePtr image = cImage::create();
        //light->m_shadowMap->copyDepthBuffer(image);
        image->saveToFile("shadowmapshot.png");
        cout << "> Saved screenshot of shadowmap to file.       \r";
    }

    // option - toggle fullscreen
    else if (a_key == GLFW_KEY_F)
    {
        // toggle state variable
        fullscreen = !fullscreen;

        // get handle to monitor
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();

        // get information about monitor
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);

        // set fullscreen or window mode
        if (fullscreen)
        {
            glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
            glfwSwapInterval(swapInterval);
        }
        else
        {
            int w = 0.8 * mode->height;
            int h = 0.5 * mode->height;
            int x = 0.5 * (mode->width - w);
            int y = 0.5 * (mode->height - h);
            glfwSetWindowMonitor(window, NULL, x, y, w, h, mode->refreshRate);
            glfwSwapInterval(swapInterval);
        }
    }

    // option - toggle vertical mirroring
    else if (a_key == GLFW_KEY_M)
    {
        mirroredDisplay = !mirroredDisplay;
        camera->setMirrorVertical(mirroredDisplay);
    }
}

//------------------------------------------------------------------------------

void close(void)
{
    // stop the simulation
    simulationRunning = false;

    // wait for graphics and haptics loops to terminate
    while (!simulationFinished) { cSleepMs(100); }

    // close haptic device
    tool->stop();

    // delete resources
    delete hapticsThread;
    delete world;
    delete handler;
}

//------------------------------------------------------------------------------

void updateGraphics(void)
{
    /////////////////////////////////////////////////////////////////////
    // UPDATE WIDGETS
    /////////////////////////////////////////////////////////////////////

    /*
    // update haptic and graphic rate data
    labelRates->setText(cStr(freqCounterGraphics.getFrequency(), 0) + " Hz / " +
                        cStr(freqCounterHaptics.getFrequency(), 0) + " Hz");
    */

    // update position of label
    labelMessage->setLocalPos(5, (int)(0.63 * (width - labelMessage->getWidth())));


    /////////////////////////////////////////////////////////////////////
    // RENDER SCENE
    /////////////////////////////////////////////////////////////////////

    // update shadow maps (if any)
    world->updateShadowMaps(false, mirroredDisplay);

    // render world
    camera->renderView(width, height);

    // wait until all GL commands are completed
    glFinish();

    // check for any OpenGL errors
    GLenum err = glGetError();
    if (err != GL_NO_ERROR) cout << "Error: " << gluErrorString(err) << endl;
}

//------------------------------------------------------------------------------

enum cMode
{
    IDLE,
    SELECTION
};

void updateHaptics(void)
{
    cMode state = IDLE;
    cGenericObject* object = NULL;
    cTransform tool_T_object;
    
    // simulation in now running
    simulationRunning  = true;
    simulationFinished = false;
    
    // main haptic simulation loop
    while(simulationRunning)
    {
        /////////////////////////////////////////////////////////////////////////
        // HAPTIC RENDERING
        /////////////////////////////////////////////////////////////////////////
        
        // compute global reference frames for each object
        world->computeGlobalPositions(true);
        
        // update position and orientation of tool
        tool->updateFromDevice();
        
        // compute interaction forces
        tool->computeInteractionForces();
        
        
        // read position
        cVector3d position;
        hapticDevice->getPosition(position);
        
        cMatrix3d rotation;
        hapticDevice->getRotation(rotation);
        
        // read gripper position
        double gripperAngle;
        hapticDevice->getGripperAngleRad(gripperAngle);
        
        // read linear velocity
        cVector3d linearVelocity;
        hapticDevice->getLinearVelocity(linearVelocity);
        
        // read angular velocity
        cVector3d angularVelocity;
        hapticDevice->getAngularVelocity(angularVelocity);
        
        // read gripper angular velocity
        double gripperAngularVelocity;
        hapticDevice->getGripperAngularVelocity(gripperAngularVelocity);
        
        // desired position
        cVector3d desiredPosition;  //set desired position to position detected by device
        desiredPosition = position;
        
        // desired orientation
        cMatrix3d desiredRotation;
        desiredRotation.identity();
        
        /////////////////////////////////////////////////////////////////////////
        // HAPTIC MANIPULATION
        /////////////////////////////////////////////////////////////////////////
        
        // compute transformation from world to tool (haptic device)
        cTransform world_T_tool = tool->getDeviceGlobalTransform();
        
        // get status of user switch
        bool button = tool->getUserSwitch(0);
        
        
        cVector3d force (0,0,0);
        cVector3d torque (0,0,0);
        double gripperForce = 0.0;
        /*
        if (useForceField) {
            double Kp = -200; //[N/m]
            cVector3d forceField;
            
            forceField = Kp * position;
            cout << displacement << endl;
            force.add(forceField);
            
            // compute angular torque
            double Kr = 0.05; // [N/m.rad]
            cVector3d axis;
            double angle;
            cMatrix3d deltaRotation = cTranspose(rotation) * desiredRotation;
            deltaRotation.toAxisAngle(axis, angle);
            torque = rotation * ((Kr * angle) * axis);
        }
        
        if (useDamping)
        {
            //DAMPING:defined as the ability to resist oscillations.
            cHapticDeviceInfo info = hapticDevice->getSpecifications();
            
            // compute linear damping force
            double Kv = .3 * info.m_maxLinearDamping;
            cVector3d forceDamping = -Kv * linearVelocity;
            force.add(forceDamping);
            
            // compute angular damping force
            double Kvr = 1.0 * info.m_maxAngularDamping;
            cVector3d torqueDamping = -Kvr * angularVelocity;
            torque.add(torqueDamping);
            
            // compute gripper angular damping force
            double Kvg = 1.0 * info.m_maxGripperAngularDamping;
            gripperForce = gripperForce - Kvg * gripperAngularVelocity;
        }*/
        
        //
        // STATE 1:
        // Idle mode - user presses the user switch
        //
        if ((state == IDLE) && (button == true))
        {
            // check if at least one contact has occurred
            if (tool->m_hapticPoint->getNumCollisionEvents() > 0)
            {
                useDamping = true;
                useForceField = true;
                hapticDevice -> getPosition(init_pos); //sets initial position to where they first press button
                
                // get contact event
                cCollisionEvent* collisionEvent = tool->m_hapticPoint->getCollisionEvent(0);
                
                // get object from contact event
                object = collisionEvent->m_object;
                
                // get transformation from object
                cTransform world_T_object = object->getGlobalTransform();
                
                // compute inverse transformation from contact point to object
                cTransform tool_T_world = world_T_tool;
                tool_T_world.invert();
                
                // store current transformation tool
                tool_T_object = tool_T_world * world_T_object;
                
                // update state
                state = SELECTION;
            }
        }
        
        //
        // STATE 2:
        // Selection mode - operator maintains user switch enabled and moves object
        //
        else if ((state == SELECTION) && (button == true))
        {
            //compute new tranformation of object in global coordinates
            cTransform world_T_object = world_T_tool * tool_T_object;
            
            // compute new tranformation of object in local coordinates
            cTransform parent_T_world = object->getParent()->getLocalTransform();
            parent_T_world.invert();
            cTransform parent_T_object = parent_T_world * world_T_object;
            
            cVector3d position;
            hapticDevice->getPosition(position);
            
            displacement = position.distance(init_pos); //recalculating displacement for string force
            
            top->m_pointB = parent_T_object.getLocalPos();
            bottom->m_pointA = parent_T_object.getLocalPos();
            
            arrow->setLocalPos(0.0, 0.5, 0.0);
            
            hapticDevice->setForceAndTorqueAndGripperForce(force, torque, gripperForce);
        }
        
        //
        // STATE 3:
        // Finalize Selection mode - operator releases user switch.
        //
        else
        {
            
            useDamping = false;
            useForceField = false;
            state = IDLE;
            top->m_pointB = cVector3d(0,0,0);
            bottom->m_pointA = cVector3d(0,0,0);
            //pig3->setLocalPos(-2.0, 1.0, -3.3);
            arrow->setLocalPos(3.0, 0.5, 0.0);
            displacement = 0.0;
        }
        
        
        
        /////////////////////////////////////////////////////////////////////////
        // FINALIZE
        /////////////////////////////////////////////////////////////////////////
        // send forces to haptic device
        tool->applyToDevice();
        //signal frequency counter
        freqCounterHaptics.signal(1);
    }
    
    // exit haptics thread
    simulationFinished = true;
}

//------------------------------------------------------------------------------
