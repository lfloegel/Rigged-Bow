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
    \author    Sebastien Grange
    \version   $MAJOR.$MINOR.$RELEASE $Rev: 1869 $
 */
//==============================================================================

//------------------------------------------------------------------------------
#ifndef CHAI3D_LOGOH
#define CHAI3D_LOGOH
//------------------------------------------------------------------------------
#include "graphics/CImage.h"
#include "files/CFileImagePNG.h"
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
namespace chai3d {
//------------------------------------------------------------------------------

const unsigned char CHAI3D_LOGO_WHITE_BYTEARRAY[] =
{
	0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0x19, 0x08, 0x06, 0x00, 0x00, 0x00, 0xc7, 0x5e, 0x8b, 0x4b, 0x00, 0x00, 0x07, 0x54, 0x49, 0x44, 0x41, 0x54, 0x68, 0x81, 0xed, 0xda, 0x7b, 0xb0, 0x55, 0x55, 0x1d, 0x07, 0xf0, 0xcf, 0x39, 0x70, 0xaf, 0x3c, 0x92, 0x97, 0xa8, 0x08, 0x14, 0x14, 0xbd, 0x14, 0x0b, 0xc1, 0xcc, 0x9c, 0x4a, 0x4b, 0x93, 0x2c, 0x52, 0x29, 0x2d, 0x4d, 0xa5, 0x07, 0x93, 0x53, 0xd3, 0x4c, 0x46, 0xa5, 0xf4, 0x40, 0x9b, 0x26, 0x6b, 0xb2, 0xc7, 0xd4, 0x1f, 0x56, 0x66, 0xf9, 0xca, 0xde, 0x45, 0x39, 0xd4, 0x58, 0xa6, 0x53, 0x96, 0x38, 0x14, 0x56, 0x94, 0x0a, 0x82, 0x26, 0x88, 0x41, 0x3c, 0x14, 0x79, 0xc7, 0x43, 0xb8, 0xe7, 0xf4, 0xc7, 0x6f, 0xef, 0x7b, 0xd7, 0x39, 0xec, 0x7d, 0xee, 0xed, 0xde, 0x4b, 0x31, 0x4e, 0xdf, 0x99, 0x3d, 0x67, 0x3d, 0x7f, 0xfb, 0xb7, 0xd6, 0x6f, 0xad, 0xdf, 0x6b, 0x9f, 0x4a, 0xbd, 0x5e, 0xf7, 0x7f, 0x1c, 0x3a, 0x18, 0xd8, 0x8f, 0xb4, 0xc6, 0xe2, 0x42, 0x54, 0xb0, 0x13, 0x37, 0xe3, 0xe9, 0x7e, 0xa4, 0xdf, 0x1b, 0x54, 0xf0, 0x41, 0xcc, 0xc6, 0x1f, 0x71, 0x39, 0xb6, 0xe7, 0x9d, 0x1d, 0x8b, 0x3e, 0xa4, 0xb6, 0xe2, 0x26, 0xda, 0x0e, 0xcf, 0x9b, 0xaa, 0x38, 0x1f, 0x33, 0x30, 0x05, 0x83, 0xb2, 0xf6, 0xa7, 0xb0, 0x10, 0xb7, 0x61, 0x71, 0x3f, 0xf1, 0x36, 0x06, 0x17, 0x65, 0x3c, 0x6e, 0x6d, 0x9b, 0xb5, 0xf6, 0x46, 0xa8, 0xf4, 0xe3, 0x0d, 0x79, 0x0d, 0xee, 0xce, 0xca, 0xbb, 0x31, 0x0e, 0x5b, 0xfa, 0x8b, 0x78, 0x2f, 0x71, 0x1a, 0x7e, 0x97, 0xd4, 0x3f, 0x8b, 0x2b, 0xf3, 0xca, 0xfe, 0x3b, 0x66, 0xaa, 
	0xaf, 0x5f, 0xc8, 0xc0, 0xc1, 0x30, 0x1e, 0xdf, 0x11, 0xeb, 0x28, 0x43, 0x1d, 0xd7, 0xe2, 0xc3, 0xe8, 0xe8, 0x23, 0x6f, 0xaf, 0x12, 0x42, 0x86, 0x2d, 0x6d, 0xb3, 0xd6, 0x8e, 0xa2, 0x7f, 0x6f, 0x48, 0xca, 0xe0, 0x0e, 0xc1, 0xfc, 0xff, 0x1a, 0xa3, 0x9a, 0xea, 0xe3, 0xf3, 0x42, 0xfd, 0x89, 0xfb, 0xd4, 0x37, 0x2e, 0x66, 0xc0, 0x20, 0x38, 0x1a, 0x77, 0x60, 0x72, 0x32, 0xb6, 0x8e, 0x5d, 0xe2, 0x04, 0x0f, 0xc9, 0xda, 0x2a, 0xb8, 0x0c, 0xfb, 0xf1, 0x91, 0x3e, 0xf2, 0xd6, 0xbc, 0x5f, 0x88, 0x2b, 0xfa, 0x4c, 0xc6, 0xdd, 0xf8, 0x4d, 0x56, 0x5e, 0x85, 0xcf, 0xe7, 0x1d, 0xb5, 0xe5, 0x37, 0xd0, 0xb1, 0x8b, 0x4a, 0x05, 0xde, 0xa7, 0x51, 0x18, 0xb7, 0x61, 0x2a, 0x8e, 0xcd, 0x9e, 0xb3, 0xf1, 0xb7, 0xa4, 0x7f, 0x0e, 0x4e, 0x38, 0x18, 0x0c, 0xf7, 0xe7, 0x0d, 0x39, 0x14, 0xb1, 0x15, 0x67, 0x61, 0x1a, 0x56, 0x0a, 0x5b, 0x40, 0xbd, 0xa6, 0xbe, 0xe9, 0xaf, 0x54, 0xdb, 0xf3, 0x71, 0xdf, 0xc3, 0x68, 0x5c, 0x8a, 0x65, 0x78, 0x3b, 0xf6, 0x26, 0x74, 0xfe, 0x81, 0x25, 0xc2, 0x7e, 0x8c, 0x17, 0x07, 0xf9, 0x4d, 0x1a, 0x85, 0xd4, 0x2f, 0x78, 0xa6, 0xdf, 0x10, 0x42, 0xbd, 0xdc, 0x27, 0x17, 0x06, 0x54, 0x2a, 0x2a, 0x13, 0x66, 0xd0, 0xb1, 0x47, 0xa6, 0x59, 0x1f, 0xc5, 0x07, 0xc4, 0xad, 0x38, 0x5b, 0xa3, 0x30, 0x72, 0xac, 0xc3, 0xf7, 0x93, 0xfa, 0xd4, 0x83, 0xc1, 0x6c, 0xd9, 0x0d, 0x99, 0x20, 0xbc, 0x8c, 0xd1, 0x42, 0x6f, 0x6e, 0xc2, 0x03, 0x78, 0xec, 0x3f, 0xa0, 0x9d, 0x7b, 0x58, 0x87, 0x09, 0x0f, 0x6c, 0x0f, 0xd6, 0xf7, 0x82, 0xc7, 0xe7, 0x66, 0xbc, 0x1c, 0x91, 0xd5, 0x37, 0xe3, 0x41, 0xb1, 0x89, 0x3d, 0xc1, 0xb8, 0x8c, 0x87, 0xba, 0xd8, 0xd4, 
	0xbd, 0x54, 0x0c, 0x78, 0xd9, 0xa7, 0xa8, 0xed, 0x57, 0x5b, 0xf6, 0x75, 0x06, 0xe6, 0x26, 0xc2, 0xf2, 0x6e, 0x68, 0x6d, 0x4c, 0xca, 0xcf, 0xe9, 0xe1, 0xfb, 0x73, 0x1c, 0x93, 0xf1, 0xb1, 0x46, 0xd8, 0x8f, 0x42, 0xa7, 0xa0, 0x59, 0x20, 0x47, 0xe2, 0x73, 0xb8, 0x00, 0xcf, 0x6a, 0xea, 0xfb, 0x17, 0x16, 0x60, 0x1e, 0x56, 0x77, 0xf3, 0xf2, 0x0e, 0xc1, 0xf0, 0x7b, 0x30, 0x13, 0xcf, 0x16, 0xa7, 0xee, 0x11, 0x71, 0xca, 0xae, 0xc5, 0xbe, 0x6e, 0x68, 0x0c, 0xc7, 0x97, 0x84, 0xfa, 0x18, 0xda, 0xd4, 0xb7, 0x47, 0xe8, 0xf9, 0x2b, 0xf0, 0xcf, 0x16, 0x34, 0x46, 0xe0, 0x5e, 0x71, 0x20, 0xe0, 0x5c, 0x61, 0xbc, 0xc1, 0x80, 0x93, 0xae, 0x56, 0xdf, 0x70, 0xaf, 0xfa, 0xe6, 0xa5, 0xb9, 0x71, 0xef, 0x0e, 0xa3, 0x93, 0xf2, 0x8e, 0xd2, 0x51, 0x5d, 0x18, 0x2c, 0xdc, 0xee, 0xb7, 0xe2, 0xf9, 0x68, 0x17, 0x07, 0xe9, 0x6b, 0x62, 0x2f, 0x0e, 0x40, 0x2a, 0x90, 0x51, 0xb8, 0x1d, 0x27, 0x95, 0x10, 0x1f, 0x2a, 0xfc, 0xe6, 0x57, 0x62, 0x7a, 0x19, 0xc1, 0x0c, 0x47, 0x60, 0x11, 0x46, 0x26, 0x6d, 0xed, 0x38, 0x31, 0x7b, 0xce, 0x14, 0x42, 0xdf, 0x7e, 0xe0, 0xd4, 0xce, 0x77, 0xcd, 0xc7, 0xeb, 0x4a, 0xfa, 0x07, 0x09, 0x41, 0x4d, 0xc1, 0x19, 0xd8, 0x50, 0x32, 0xae, 0x2a, 0x0e, 0x56, 0x6e, 0x2c, 0xda, 0x1b, 0x7a, 0x2b, 0x15, 0xd5, 0xc9, 0xef, 0xd7, 0x71, 0xcf, 0x7b, 0x5b, 0x2c, 0xa5, 0x13, 0x23, 0x70, 0x5e, 0x52, 0x5f, 0x58, 0x36, 0x30, 0xc3, 0x68, 0xb1, 0x86, 0xd3, 0x9a, 0xda, 0x8f, 0xc7, 0x75, 0x4a, 0x42, 0x82, 0xd4, 0x86, 0x7c, 0x41, 0xa3, 0x30, 0xfe, 0x8e, 0x6b, 0x70, 0x35, 0x1e, 0x4a, 0xda, 0x27, 0xe0, 0x07, 0x68, 0x6b, 0xc1, 0x4c, 0xbb, 0x2e, 0x61, 
	0xac, 0xc9, 0x68, 0xa5, 0x41, 0xe2, 0x59, 0xb8, 0xbe, 0x64, 0x6e, 0x45, 0xdc, 0xa0, 0x54, 0x18, 0x8f, 0x0b, 0x0f, 0xe9, 0x33, 0xb8, 0x3f, 0x69, 0x3f, 0x4e, 0x9c, 0xb6, 0x4a, 0x0b, 0x5e, 0x52, 0xd5, 0x70, 0xa0, 0x2b, 0xbe, 0x77, 0x73, 0xd1, 0x9c, 0x11, 0xc2, 0x15, 0x3e, 0x4a, 0xa8, 0x9a, 0x33, 0xf1, 0x2b, 0xbc, 0x30, 0xeb, 0xdf, 0x82, 0x9b, 0x5a, 0xbc, 0xb3, 0x8a, 0x5b, 0x34, 0x0a, 0x63, 0xa7, 0xd8, 0x87, 0x27, 0xb3, 0xfa, 0x48, 0x05, 0xc8, 0x05, 0x32, 0x01, 0xb3, 0x92, 0xf6, 0x9f, 0x0b, 0xcf, 0xe4, 0xe3, 0xf8, 0x24, 0x4e, 0xd1, 0x15, 0xf4, 0xed, 0x13, 0x9b, 0xd2, 0x9d, 0x43, 0xb0, 0x03, 0xef, 0xc4, 0x8b, 0x85, 0x4b, 0x39, 0x0d, 0xbf, 0x4f, 0xfa, 0x2f, 0xc4, 0xab, 0x4b, 0xe6, 0x6e, 0xd0, 0xa5, 0x12, 0x96, 0xe0, 0x64, 0x7c, 0x0c, 0x57, 0x89, 0x43, 0xf3, 0xdd, 0x64, 0xec, 0x4c, 0xe1, 0x9a, 0xf6, 0x0a, 0xb5, 0x35, 0x77, 0x29, 0x90, 0xe7, 0x02, 0x3c, 0x2c, 0xb4, 0xc0, 0xc3, 0xb8, 0x13, 0xaf, 0xc8, 0xfa, 0x76, 0x08, 0x55, 0xfc, 0x78, 0x0b, 0xb2, 0xaf, 0x17, 0xd1, 0x7e, 0x8e, 0x1f, 0xe1, 0x25, 0x62, 0x1f, 0x8e, 0x15, 0x01, 0x6a, 0x21, 0xf2, 0x4d, 0x3d, 0x55, 0xd7, 0x75, 0xde, 0x21, 0xf4, 0xde, 0xce, 0x64, 0xdc, 0x76, 0x5c, 0x82, 0x2f, 0xe2, 0xe5, 0x22, 0x15, 0x51, 0xe4, 0x89, 0xa4, 0x98, 0x87, 0x5b, 0x45, 0x70, 0xb5, 0x4f, 0xb8, 0x93, 0x6f, 0xd1, 0xa8, 0x5e, 0xce, 0x2b, 0x98, 0x57, 0xc7, 0x27, 0x84, 0x00, 0xaf, 0x11, 0xaa, 0x29, 0x35, 0xa6, 0xfb, 0x44, 0x0a, 0x24, 0xbf, 0xf2, 0x55, 0xad, 0xa3, 0xeb, 0xd6, 0xa8, 0x0e, 0x28, 0x6a, 0x3d, 0x4a, 0xd8, 0xb0, 0xe1, 0x38, 0xbc, 0xa9, 0xef, 0x3a, 0xfc, 0xac, 0x1b, 0xaa, 0xe7, 
	0x26, 0xe5, 0x65, 0xb8, 0x58, 0xd8, 0xdd, 0x7d, 0xc2, 0xdb, 0xbb, 0x52, 0x08, 0xe9, 0x40, 0x76, 0xb2, 0xdf, 0xd4, 0x63, 0x58, 0x27, 0xfc, 0xee, 0x66, 0xac, 0xc3, 0x5c, 0x3d, 0xf3, 0xbd, 0xb7, 0xe3, 0x27, 0x05, 0xed, 0x9b, 0xf1, 0xeb, 0xa4, 0x3e, 0xae, 0x05, 0x8d, 0x47, 0xc5, 0x0d, 0x2d, 0xb2, 0x55, 0x1b, 0x85, 0x2a, 0xcc, 0x51, 0x78, 0xfd, 0x7b, 0x84, 0x7a, 0x5d, 0x81, 0x26, 0x5b, 0x23, 0x3c, 0xcb, 0xfc, 0x49, 0x07, 0x5c, 0x2a, 0x6c, 0x68, 0x2b, 0x8c, 0x49, 0xca, 0x3f, 0x56, 0xec, 0x51, 0x7d, 0xbb, 0x68, 0x62, 0x2e, 0x90, 0xf4, 0x85, 0x75, 0x7d, 0x8f, 0x4f, 0x76, 0x8b, 0x9b, 0x51, 0x84, 0xd5, 0x49, 0xb9, 0xbd, 0x64, 0x4c, 0x8a, 0x41, 0xc2, 0x40, 0xa6, 0xcf, 0x91, 0x1a, 0x79, 0x6c, 0x65, 0x43, 0x5a, 0xa2, 0x3a, 0xe9, 0x7c, 0x05, 0xcb, 0x3d, 0x07, 0xcf, 0xcb, 0x9e, 0x49, 0x42, 0x4d, 0xe6, 0xde, 0xd9, 0x48, 0xdc, 0xe8, 0xc0, 0xb4, 0x4c, 0x8a, 0xd4, 0x59, 0xda, 0x56, 0x32, 0xe6, 0xa9, 0xa2, 0xc6, 0x83, 0x15, 0xa9, 0x57, 0x94, 0x0b, 0x35, 0x6d, 0x6f, 0x95, 0xef, 0x3a, 0x46, 0xa8, 0xbd, 0x19, 0xc2, 0xc8, 0xa6, 0x9b, 0x5e, 0xd1, 0xe8, 0x96, 0xf7, 0x44, 0xb0, 0x85, 0xa8, 0x8c, 0x9c, 0x4c, 0xb5, 0x2d, 0x63, 0xa5, 0xf3, 0x15, 0x7b, 0xb2, 0x27, 0xc7, 0x5f, 0x84, 0xad, 0x5a, 0x2c, 0x3c, 0xbb, 0xf1, 0x78, 0x17, 0xbe, 0x5c, 0x42, 0x36, 0x5d, 0x57, 0xd9, 0x3e, 0x14, 0xea, 0xca, 0x43, 0x35, 0x75, 0x32, 0x56, 0x64, 0x69, 0x5f, 0x70, 0xb0, 0x5f, 0x54, 0x7b, 0xe8, 0xfa, 0x88, 0xd8, 0xab, 0xcd, 0x61, 0xd7, 0x01, 0xd8, 0x2b, 0x62, 0x9f, 0x29, 0x59, 0x7d, 0xba, 0x72, 0x81, 0xf4, 0x1a, 0x87, 0xaa, 0x40, 0xe6, 0xe9, 0x12, 0xc6, 0x16, 
	0xfc, 0x50, 0xd8, 0x9f, 0xaa, 0xae, 0xa3, 0x3c, 0x5b, 0xb8, 0xa6, 0xbd, 0x46, 0x7d, 0xfb, 0x4a, 0xb5, 0xd5, 0xbf, 0xc8, 0xd3, 0xef, 0x3d, 0x41, 0x1a, 0x0c, 0xb6, 0x7a, 0x77, 0x7a, 0x9b, 0x6b, 0x25, 0x63, 0x0a, 0xdb, 0x73, 0x81, 0x34, 0x5f, 0xab, 0x32, 0x22, 0xff, 0x0d, 0x0c, 0xd2, 0xe8, 0x32, 0xce, 0x11, 0xde, 0x5a, 0x33, 0xde, 0xa8, 0x8f, 0x02, 0xa9, 0x2d, 0xfd, 0x6a, 0xc4, 0x21, 0xed, 0xc3, 0x7a, 0x3a, 0x25, 0xdd, 0xa7, 0x9d, 0xa5, 0xa3, 0x1a, 0xf7, 0x6f, 0x48, 0xc9, 0x98, 0xc2, 0x2b, 0x99, 0xbf, 0x20, 0xf5, 0x58, 0xc6, 0x8a, 0x54, 0x47, 0x33, 0x26, 0x8a, 0x60, 0xa8, 0x2c, 0x76, 0xe8, 0x2f, 0x0c, 0xce, 0x9e, 0x1c, 0x0f, 0x14, 0x8c, 0x39, 0x55, 0x1f, 0x62, 0x0f, 0xa8, 0x6f, 0x59, 0xa1, 0xb6, 0x72, 0x3e, 0x6d, 0x9d, 0xfb, 0x32, 0x1a, 0x9f, 0xc6, 0x3b, 0x5a, 0x4c, 0x9b, 0x96, 0x94, 0x57, 0xb6, 0x18, 0x97, 0xe6, 0xec, 0xde, 0xa6, 0x58, 0x13, 0xcd, 0x2e, 0x9a, 0x98, 0x0b, 0xe4, 0x1e, 0x5d, 0xb9, 0xa5, 0x61, 0xf8, 0x8a, 0x46, 0xa3, 0xd3, 0x26, 0x84, 0xf1, 0xee, 0x6c, 0xec, 0x7c, 0x5d, 0x9f, 0x37, 0xfb, 0x1b, 0xcd, 0x06, 0xf5, 0xe2, 0xa6, 0xfe, 0x97, 0x8a, 0x28, 0xb8, 0xd7, 0x86, 0x1c, 0x6a, 0x8f, 0xdc, 0xcc, 0xd3, 0x5b, 0xa9, 0x54, 0x89, 0x94, 0xd0, 0xfd, 0x22, 0xf0, 0xfc, 0x86, 0xc6, 0x8d, 0xcf, 0x31, 0x53, 0xe4, 0xa4, 0x72, 0xfc, 0xa9, 0x05, 0xf9, 0x05, 0x49, 0xf9, 0x04, 0xb1, 0x77, 0x79, 0x1e, 0x6c, 0x88, 0x50, 0xc9, 0x17, 0x15, 0x4d, 0xcc, 0x25, 0xf7, 0x98, 0x08, 0x76, 0x2e, 0xc8, 0xea, 0x6f, 0x16, 0xb9, 0x9a, 0xdb, 0xc5, 0xf5, 0x9b, 0x21, 0x72, 0x58, 0x39, 0xc6, 0xeb, 0xfb, 0x27, 0xcc, 0x32, 0xec, 0xc6, 0x6f, 
	0x85, 0x17, 0x43, 0x04, 0x81, 0x67, 0x88, 0xd8, 0x63, 0xa4, 0x58, 0xe0, 0x61, 0x7d, 0x7e, 0x4b, 0xdb, 0x70, 0x89, 0xaa, 0x1f, 0xa8, 0x2b, 0x01, 0x39, 0x18, 0xbf, 0x14, 0x42, 0x5f, 0x9f, 0xf5, 0x4d, 0x15, 0x99, 0x85, 0xfc, 0x90, 0x6e, 0xc2, 0x4f, 0x5b, 0x50, 0xbf, 0x4b, 0x64, 0x36, 0x5e, 0x9b, 0xd5, 0x67, 0xe1, 0x0d, 0x58, 0x21, 0xf6, 0x6e, 0x62, 0xd9, 0xc4, 0xf4, 0x2a, 0xcd, 0x11, 0xe1, 0xfd, 0x71, 0x59, 0xfd, 0x94, 0xec, 0x69, 0xc6, 0x2a, 0x71, 0x6a, 0x9b, 0xb3, 0xb5, 0xa9, 0x21, 0x2b, 0x74, 0xe9, 0x32, 0x54, 0x4b, 0xca, 0x29, 0xae, 0x12, 0xaa, 0x71, 0x52, 0x56, 0x2f, 0xfa, 0xf6, 0xb0, 0x4d, 0x44, 0xd2, 0xad, 0xe8, 0x34, 0xf3, 0xd2, 0xc9, 0x63, 0x75, 0xe2, 0x39, 0x61, 0x43, 0xea, 0x35, 0x2a, 0xd5, 0x5b, 0x45, 0xd2, 0xf3, 0xb2, 0xac, 0xfb, 0x68, 0x7c, 0xb4, 0x84, 0x5e, 0x4d, 0x7c, 0x61, 0x2c, 0x4b, 0x68, 0x12, 0x7b, 0x73, 0x89, 0x38, 0xe4, 0x27, 0x67, 0x6d, 0xa3, 0xc5, 0x77, 0xf4, 0x1c, 0x7b, 0x85, 0xe6, 0xa9, 0xa6, 0x3c, 0xa6, 0x0b, 0xd9, 0x20, 0x24, 0x7a, 0x8b, 0xe2, 0xd4, 0xf2, 0x5e, 0x71, 0x2a, 0x4e, 0x57, 0xac, 0x3f, 0xf7, 0x89, 0xd3, 0xbd, 0x27, 0x9b, 0x5f, 0xe6, 0x18, 0xe4, 0x63, 0xf6, 0x88, 0x94, 0x7e, 0x11, 0xd6, 0x8a, 0x74, 0xc8, 0x37, 0x45, 0xce, 0x68, 0x67, 0x42, 0x77, 0xb1, 0xf8, 0x5a, 0x37, 0x37, 0xa1, 0xb5, 0xbb, 0x84, 0x4e, 0x2d, 0x9b, 0x93, 0x8f, 0xe9, 0x4c, 0x70, 0x56, 0x46, 0x1d, 0xaf, 0x3a, 0xee, 0xf4, 0xec, 0x23, 0x15, 0x22, 0x5d, 0x34, 0x57, 0xeb, 0x8d, 0x5e, 0x22, 0x4e, 0x7a, 0xab, 0xdb, 0x91, 0x63, 0x9d, 0xd8, 0xcf, 0x2b, 0x44, 0x76, 0x63, 0xb3, 0x08, 0x96, 0xd7, 0xe2, 0x06, 0x71, 0x00, 
	0xfe, 0x9c, 0xf1, 0xd6, 0xe9, 0x20, 0x94, 0xfd, 0xeb, 0xe4, 0x44, 0xb1, 0x21, 0x63, 0xc4, 0xa9, 0x7a, 0x12, 0x7f, 0x10, 0xdf, 0x16, 0xca, 0x36, 0x7a, 0x88, 0x48, 0x9e, 0x55, 0xc5, 0xe2, 0x97, 0x96, 0x8c, 0x1d, 0x23, 0x52, 0x35, 0x15, 0x3c, 0xa1, 0xfb, 0x8f, 0x5e, 0xe3, 0xc4, 0xe9, 0x1a, 0x94, 0x2d, 0x68, 0x95, 0x10, 0xe4, 0x30, 0x91, 0xb8, 0x24, 0x84, 0xb6, 0xb1, 0x60, 0x6e, 0x35, 0xe3, 0x69, 0x48, 0xc6, 0xcb, 0x72, 0xc9, 0xe2, 0x3b, 0x16, 0x5d, 0xae, 0xb6, 0xe2, 0x5b, 0xe9, 0xdf, 0x80, 0x08, 0x77, 0x7b, 0xba, 0x50, 0x2d, 0x83, 0xb3, 0x79, 0xdb, 0x44, 0xc6, 0xfb, 0x4e, 0xe5, 0x91, 0x77, 0x2b, 0x0c, 0x13, 0xeb, 0x1e, 0x2a, 0xd4, 0x5d, 0xee, 0x44, 0xbd, 0x48, 0x04, 0xbd, 0xbb, 0xda, 0x66, 0xad, 0x7d, 0x10, 0xfe, 0x0d, 0x32, 0x95, 0xbe, 0xad, 0x52, 0x1e, 0xd7, 0x59, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

const unsigned char CHAI3D_LOGO_BLACK_BYTEARRAY[] =
{
	0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0x19, 0x08, 0x06, 0x00, 0x00, 0x00, 0xc7, 0x5e, 0x8b, 0x4b, 0x00, 0x00, 0x07, 0xa2, 0x49, 0x44, 0x41, 0x54, 0x68, 0x81, 0xed, 0xd9, 0x7b, 0x8c, 0x5d, 0x55, 0x15, 0x06, 0xf0, 0xdf, 0x99, 0x3b, 0x33, 0x7d, 0x42, 0x4b, 0x79, 0x94, 0x82, 0xb4, 0xe5, 0x65, 0x91, 0x16, 0xad, 0x20, 0x11, 0x0b, 0x96, 0xa0, 0x88, 0x20, 0x12, 0x90, 0xa2, 0x88, 0xa8, 0x18, 0x1f, 0x29, 0x3e, 0x20, 0x82, 0x40, 0x22, 0x46, 0x25, 0xc6, 0x04, 0x1f, 0x28, 0x88, 0x26, 0x56, 0x8d, 0x04, 0x8c, 0xa2, 0x96, 0x87, 0x41, 0x45, 0x94, 0x87, 0x4a, 0x0c, 0x1a, 0x11, 0x10, 0x04, 0x01, 0xc5, 0xb6, 0x28, 0x85, 0x52, 0x4a, 0x3b, 0xb4, 0x85, 0xd2, 0xce, 0xf4, 0xde, 0xe3, 0x1f, 0xeb, 0xdc, 0xb9, 0xfb, 0xde, 0xb9, 0xe7, 0xce, 0xb4, 0x33, 0x84, 0xc6, 0xf8, 0x25, 0x37, 0x77, 0x9f, 0x73, 0xf6, 0x63, 0xed, 0xbd, 0xd6, 0x5e, 0xfb, 0x5b, 0x6b, 0x67, 0x79, 0x9e, 0xfb, 0x3f, 0x76, 0x1c, 0x74, 0xc3, 0xb1, 0xc7, 0x1e, 0x37, 0x16, 0x7d, 0x4d, 0xc4, 0xc7, 0x8a, 0xff, 0x1c, 0x57, 0xe3, 0x89, 0xb1, 0xe8, 0x78, 0x94, 0x38, 0x1f, 0x1f, 0xc5, 0x5f, 0xf0, 0x09, 0xac, 0x83, 0x8d, 0xfd, 0x15, 0xe7, 0x1e, 0xb1, 0xca, 0x99, 0x87, 0xad, 0x36, 0xd0, 0x5f, 0xa9, 0xd7, 0xed, 0xc1, 0x19, 0x38, 0x01, 0xf3, 0xc5, 0x5c, 0xe0, 0x59, 0xdc, 0x85, 0x1f, 0xe3, 0x4f, 0x63, 0x24, 0xd7, 0x7e, 0x38, 0x13, 0x19, 0x56, 0xf6, 0xbc, 0x6f, 0xe5, 0x55, 0x14, 0x0a, 0x19, 0x23, 0xec, 0x8a, 0xaf, 0x26, 0xcf, 0xf7, 0x78, 0xf9, 0x15, 0x72, 0x04, 0xbe, 0x56, 0x94, 0x0f, 0xc0, 
	0x46, 0x2c, 0xce, 0xd1, 0xdb, 0x55, 0xb3, 0xdf, 0xb4, 0xcd, 0xd4, 0xb2, 0x7a, 0xdd, 0x59, 0x62, 0xc1, 0xdf, 0xd0, 0xa6, 0x9f, 0x99, 0x38, 0x14, 0xe7, 0xe0, 0x4a, 0xa1, 0xe4, 0xea, 0x28, 0x65, 0x7b, 0x2d, 0xbe, 0x50, 0x94, 0x1f, 0xc7, 0x55, 0xd0, 0x35, 0xca, 0x4e, 0x53, 0xd4, 0xc4, 0x84, 0xeb, 0xd8, 0x3a, 0x86, 0x7d, 0x6f, 0x2f, 0x76, 0x6a, 0x79, 0xde, 0x15, 0xfa, 0xb7, 0x76, 0x39, 0x68, 0xf7, 0x17, 0x1d, 0xb6, 0xf7, 0xf3, 0xaa, 0xd5, 0x2e, 0xd8, 0x0d, 0xbf, 0x36, 0x54, 0x19, 0x1b, 0xf1, 0x7c, 0xcb, 0xbb, 0x73, 0x35, 0x16, 0x72, 0x34, 0x18, 0x68, 0x19, 0x07, 0x63, 0xab, 0x90, 0x1d, 0x11, 0x7f, 0xc0, 0x4f, 0xc4, 0xa2, 0x3e, 0x88, 0x4b, 0x72, 0xe4, 0x72, 0xef, 0x9c, 0xb7, 0x56, 0x6f, 0x4f, 0x4d, 0x2d, 0x8e, 0xd0, 0x77, 0xe3, 0xa0, 0xa4, 0xdd, 0xcf, 0x85, 0xcb, 0x3a, 0xa0, 0xf8, 0x1d, 0x83, 0xbb, 0x93, 0xef, 0xe7, 0x0b, 0x97, 0x33, 0xe6, 0x18, 0x4b, 0x97, 0xb5, 0x23, 0x62, 0xb3, 0x38, 0x13, 0xf6, 0xc2, 0x1a, 0x0c, 0xe4, 0x39, 0x13, 0x7b, 0x72, 0x73, 0xf7, 0xd8, 0x94, 0xba, 0xab, 0x1f, 0x89, 0xb5, 0xb8, 0x00, 0x8f, 0x60, 0x91, 0xe6, 0x1d, 0xbe, 0x1a, 0xc7, 0xe3, 0x5e, 0xec, 0x8b, 0xf1, 0x38, 0x05, 0x5f, 0x1f, 0x6b, 0x81, 0xff, 0xd7, 0x77, 0x48, 0x1d, 0x4f, 0x29, 0x5c, 0x44, 0x57, 0xc6, 0x8b, 0x5b, 0xbb, 0xfc, 0x76, 0xf9, 0x14, 0x2a, 0x35, 0x85, 0x4a, 0xfa, 0x70, 0x05, 0xe6, 0x8a, 0x85, 0x6e, 0xe7, 0x6e, 0xfb, 0x70, 0x63, 0xf2, 0x7c, 0xe8, 0x4b, 0x21, 0x68, 0xd9, 0x0e, 0x99, 0x8a, 0xc3, 0xb1, 0x3f, 0xc6, 0xe1, 0x19, 0xdc, 0x2f, 0xac, 0x67, 0xa4, 0xa8, 0x1f, 0x7a, 0x15, 0xec, 0x5d, 0x94, 0x9f, 0x46, 0xff, 0x36, 0xca, 
	0x38, 0x1d, 0xaf, 0x13, 0x87, 0x6e, 0xb7, 0xb0, 0xf4, 0x07, 0xf0, 0xf0, 0x08, 0xdb, 0xcf, 0x14, 0x73, 0xc8, 0x05, 0xc9, 0xd8, 0xd2, 0xdb, 0x55, 0xb3, 0xe4, 0xee, 0x3d, 0x75, 0x77, 0xe5, 0xce, 0x98, 0xbf, 0xc6, 0xc0, 0xd6, 0x41, 0xbb, 0x5c, 0x3f, 0x4c, 0x5f, 0x4f, 0x27, 0xe5, 0x3d, 0x47, 0x38, 0x3e, 0x61, 0xf8, 0x7b, 0x89, 0xb5, 0xa8, 0x1b, 0x47, 0x5b, 0x52, 0xd0, 0x4e, 0x21, 0x9f, 0x11, 0xf4, 0xb0, 0x75, 0xc0, 0xaa, 0xa0, 0x7c, 0x97, 0xe0, 0x8e, 0x11, 0x08, 0x31, 0x49, 0x1c, 0x80, 0x67, 0x6b, 0xf8, 0xdb, 0x95, 0xb8, 0x01, 0x97, 0xe2, 0xb9, 0x61, 0xda, 0xf7, 0xe2, 0x2b, 0x38, 0x4b, 0x18, 0x48, 0x8a, 0x5a, 0x21, 0xc3, 0x79, 0xf8, 0x7b, 0x87, 0x3e, 0x26, 0x8a, 0x73, 0x64, 0x1f, 0xa1, 0x90, 0x13, 0x70, 0x6b, 0x96, 0xd1, 0xdb, 0x5d, 0xf3, 0xed, 0xbb, 0xf7, 0x34, 0x6f, 0xfa, 0x26, 0x87, 0xcc, 0x78, 0x21, 0x55, 0x4a, 0x27, 0xec, 0x93, 0x94, 0x37, 0x96, 0xd6, 0x6a, 0x60, 0x2a, 0x3e, 0x25, 0x5c, 0xe0, 0x6c, 0xa1, 0x90, 0x15, 0x62, 0x5e, 0x1b, 0xda, 0x35, 0x68, 0x55, 0xc8, 0x12, 0x2c, 0x2e, 0xe9, 0xbc, 0x82, 0xa3, 0xf0, 0x1b, 0xbc, 0x07, 0x4b, 0x87, 0x11, 0xe6, 0x1a, 0xec, 0xd2, 0xf2, 0x6e, 0x7f, 0x5c, 0x84, 0xe3, 0x70, 0x32, 0xfe, 0x53, 0xd2, 0xb6, 0x17, 0xd7, 0x8a, 0x89, 0xb4, 0x43, 0x17, 0xde, 0x22, 0x94, 0x72, 0x2c, 0x1e, 0x2a, 0xa9, 0x97, 0x15, 0x7d, 0x65, 0xc5, 0xaf, 0xa7, 0xfe, 0xa1, 0x92, 0xb1, 0xb9, 0x9a, 0xb9, 0xee, 0xa1, 0xdd, 0xcc, 0x9b, 0xf1, 0xc2, 0x30, 0x53, 0x41, 0x18, 0x68, 0x2a, 0xcf, 0xad, 0xc3, 0xd4, 0x9f, 0x29, 0xc8, 0xc1, 0x6b, 0x5a, 0xde, 0xcf, 0xc1, 0xf7, 0x95, 0x18, 0x64, 0x5d, 0x21, 0x99, 0x08, 
	0x52, 0x52, 0x65, 0xfc, 0x5b, 0x2c, 0xca, 0x33, 0x78, 0x23, 0x4e, 0x2d, 0xde, 0x57, 0x04, 0x5f, 0xbf, 0x07, 0xcb, 0x3b, 0x08, 0x54, 0x57, 0xc6, 0xb2, 0xa2, 0x8f, 0x59, 0x62, 0xdb, 0x12, 0x0c, 0xe6, 0x66, 0x1c, 0xa9, 0xbd, 0xa5, 0x7c, 0x4e, 0xf3, 0xe4, 0x57, 0xe0, 0x7b, 0x22, 0xa8, 0x5b, 0x28, 0x0c, 0x82, 0x70, 0x67, 0x57, 0x63, 0x81, 0x72, 0x57, 0x58, 0x4b, 0xca, 0x4d, 0x69, 0x89, 0x2c, 0x63, 0xb7, 0x89, 0x03, 0xda, 0x60, 0x77, 0x4c, 0x2e, 0xea, 0x77, 0x63, 0x1e, 0xbe, 0xa8, 0xe1, 0x7a, 0xff, 0x85, 0x1f, 0x96, 0x8c, 0x47, 0xb8, 0xc8, 0xa5, 0x9a, 0x95, 0xb1, 0x4a, 0xc4, 0x1b, 0xd3, 0x85, 0xc7, 0x68, 0xdd, 0xf5, 0x68, 0x1c, 0xea, 0xf3, 0x45, 0xd0, 0x53, 0xc7, 0xa3, 0x78, 0x3d, 0x2e, 0x16, 0x87, 0xdd, 0x22, 0x8d, 0x00, 0x8b, 0x88, 0x5a, 0xd3, 0x89, 0x96, 0xe1, 0x62, 0x71, 0x50, 0x2e, 0xc0, 0xc1, 0x62, 0x07, 0xd6, 0x31, 0x0f, 0xef, 0x2f, 0x69, 0xf7, 0x98, 0xc6, 0xee, 0x59, 0x89, 0xa3, 0x85, 0x9b, 0xfb, 0x8e, 0x30, 0x9c, 0xf3, 0x92, 0xba, 0x87, 0x09, 0x83, 0xd9, 0x66, 0x54, 0x32, 0x0e, 0xdf, 0xfb, 0x79, 0x59, 0x36, 0xe4, 0xd3, 0x35, 0x62, 0x0d, 0x1e, 0x15, 0x67, 0xd5, 0xcf, 0x8a, 0x79, 0x10, 0x8c, 0xeb, 0x2c, 0x9d, 0x5d, 0xd6, 0x49, 0x62, 0xfd, 0xea, 0xb8, 0x0a, 0xaf, 0x12, 0xeb, 0x30, 0x57, 0x87, 0x38, 0xa6, 0xae, 0x90, 0x37, 0xe1, 0x90, 0xe4, 0xfd, 0xa7, 0x8b, 0x81, 0x53, 0x5c, 0x28, 0xac, 0xe4, 0x44, 0x61, 0xa5, 0x8f, 0x77, 0x10, 0x88, 0x98, 0xd4, 0xa5, 0xd8, 0x52, 0x3c, 0xaf, 0x17, 0x29, 0x8c, 0x3f, 0x26, 0x75, 0x4e, 0xee, 0xd0, 0xf6, 0xd5, 0x82, 0xef, 0xbf, 0xc3, 0xd0, 0x88, 0xff, 0x0a, 0x11, 0x57, 0xd4, 0xb1, 
	0x60, 0x18, 0x59, 0x4a, 0x31, 0xc8, 0xb3, 0x9a, 0xb1, 0x8b, 0x70, 0x75, 0xe3, 0x24, 0x6e, 0xae, 0xc0, 0x77, 0x35, 0xcf, 0xa1, 0x1d, 0xd2, 0x79, 0xdd, 0x87, 0x8f, 0x68, 0x10, 0x86, 0xcd, 0xf8, 0xbc, 0x66, 0xc6, 0x36, 0x88, 0xba, 0xcb, 0x9a, 0x85, 0x09, 0x45, 0x79, 0x8b, 0x60, 0x54, 0xad, 0xc8, 0xf1, 0xd9, 0x61, 0x04, 0x49, 0xf1, 0xd3, 0x92, 0xf7, 0xd7, 0x6b, 0x2c, 0xe0, 0x3e, 0x85, 0x0c, 0xed, 0x68, 0xe6, 0x7a, 0x5c, 0xde, 0xa1, 0xff, 0xfb, 0x35, 0x8c, 0x68, 0x8f, 0x6d, 0x90, 0x6b, 0x10, 0x79, 0x4e, 0xb5, 0xfd, 0x3e, 0xbf, 0x4b, 0x90, 0x98, 0x5c, 0xb8, 0xe8, 0x57, 0x2a, 0xa2, 0x7c, 0x11, 0xab, 0xdc, 0x23, 0xce, 0x87, 0x32, 0xcc, 0x4e, 0xca, 0x37, 0x6a, 0xef, 0x4d, 0x96, 0x6a, 0x1c, 0x03, 0x83, 0xa8, 0x2b, 0x24, 0x6d, 0x50, 0x17, 0x64, 0xb4, 0x68, 0xeb, 0x9c, 0x35, 0xa7, 0x22, 0x7a, 0xc4, 0x84, 0x3b, 0xa5, 0x59, 0x26, 0x08, 0xbf, 0x5b, 0x69, 0x79, 0xbf, 0x73, 0x52, 0x6e, 0xfd, 0x36, 0x22, 0xe4, 0xb8, 0x7d, 0xd9, 0x14, 0x0b, 0xf6, 0xdd, 0x20, 0xd3, 0x34, 0xe9, 0x0b, 0x5a, 0xaa, 0xce, 0x10, 0xc6, 0x71, 0x7a, 0x21, 0xcf, 0x37, 0xf1, 0x7b, 0x25, 0x4c, 0x49, 0x73, 0x7c, 0x57, 0xe6, 0xda, 0xda, 0x32, 0x89, 0xb2, 0x38, 0xa4, 0xed, 0x3e, 0xde, 0x46, 0x94, 0xf5, 0x91, 0x0a, 0xdb, 0x49, 0xf1, 0xd3, 0x04, 0xc5, 0x3e, 0x45, 0x2c, 0x48, 0xeb, 0xa2, 0x8f, 0x5a, 0xc6, 0x4a, 0x57, 0x6e, 0xd9, 0xba, 0x09, 0xb6, 0x0c, 0x74, 0x19, 0x5f, 0xa9, 0xc9, 0xf3, 0xd2, 0x2e, 0x57, 0x89, 0xb3, 0x6b, 0x8e, 0x38, 0x6f, 0x67, 0x0a, 0x62, 0xb1, 0xa4, 0xa4, 0x7e, 0x3a, 0xaf, 0x32, 0x3e, 0xdd, 0xf6, 0xfd, 0x8e, 0x1a, 0xa9, 0xef, 0x24, 0x68, 0xe5, 
	0x39, 0x1a, 0x6e, 0x2d, 0x6b, 0xf9, 0xa5, 0xd8, 0xae, 0x79, 0xf4, 0x57, 0x33, 0xa7, 0x1c, 0xbc, 0xd6, 0xa4, 0x71, 0x55, 0xb5, 0x72, 0x65, 0xd4, 0x51, 0xc5, 0x2f, 0x92, 0xe7, 0xe3, 0xb7, 0x67, 0xcc, 0xe1, 0x50, 0xb6, 0x43, 0x5e, 0xee, 0x5b, 0xab, 0xb3, 0x05, 0x7b, 0x22, 0xb6, 0xfc, 0x37, 0xf0, 0xa4, 0x86, 0x22, 0x72, 0x7c, 0x40, 0x83, 0xc9, 0x6c, 0xb3, 0x42, 0xfa, 0xab, 0x99, 0x59, 0x53, 0xb7, 0x78, 0xeb, 0x01, 0xcf, 0xa9, 0x6e, 0x1d, 0xf1, 0x66, 0x4b, 0xdd, 0x4f, 0x6b, 0x26, 0x39, 0x45, 0xda, 0x61, 0x19, 0x1b, 0x6d, 0xfb, 0xbe, 0x9d, 0x42, 0xba, 0x6d, 0xa7, 0x4f, 0x1e, 0x43, 0x9c, 0x94, 0x94, 0xaf, 0xd4, 0x9e, 0x4c, 0x1c, 0xad, 0x99, 0x5a, 0x6e, 0x13, 0xfa, 0xab, 0x99, 0xd3, 0xe6, 0xae, 0xb5, 0xf3, 0xa4, 0x81, 0xf4, 0x82, 0x6a, 0x38, 0xf4, 0x26, 0xe5, 0x4d, 0x1d, 0xea, 0xa5, 0x67, 0xe2, 0xae, 0x25, 0x75, 0x5a, 0x83, 0x66, 0x34, 0x2c, 0x6b, 0x45, 0x32, 0x40, 0xaf, 0xc8, 0x63, 0xb5, 0x62, 0x9c, 0xa0, 0xa3, 0x8b, 0x8b, 0xf2, 0x4b, 0x89, 0xf4, 0xc0, 0x7e, 0xb2, 0xcd, 0xf7, 0xd9, 0x22, 0x0d, 0xb2, 0x5d, 0x18, 0xa8, 0x66, 0x66, 0x4f, 0xdd, 0xe2, 0xb8, 0x03, 0x9f, 0x53, 0x1d, 0x18, 0xdc, 0x5c, 0xd3, 0xf1, 0x65, 0xb1, 0x3b, 0xcb, 0x90, 0xde, 0x97, 0x2c, 0xeb, 0x50, 0x6f, 0x45, 0x52, 0x5e, 0x64, 0x28, 0x75, 0x26, 0x52, 0xfe, 0x43, 0x50, 0x97, 0xe6, 0x36, 0x41, 0xe5, 0xea, 0xf8, 0x92, 0x08, 0xe4, 0xd2, 0x7a, 0x4b, 0x44, 0x20, 0xb7, 0x04, 0x7f, 0xd3, 0x7c, 0x7f, 0x30, 0xd6, 0x48, 0x63, 0xa0, 0xd3, 0x04, 0xad, 0xed, 0x16, 0x86, 0x30, 0x1f, 0xd7, 0x61, 0xca, 0xf6, 0x76, 0xde, 0x5f, 0xcd, 0x9c, 0x38, 0xa7, 0xcf, 0x94, 0x49, 
	0x03, 0xf5, 0xb3, 0xe3, 0x34, 0x91, 0x7e, 0xb9, 0x48, 0xec, 0xc8, 0x21, 0x74, 0x54, 0x5c, 0x4f, 0xa7, 0x46, 0xd0, 0x29, 0x9f, 0x97, 0xa6, 0x95, 0xe6, 0x8a, 0x3b, 0x99, 0x03, 0x0b, 0xf9, 0x5f, 0x81, 0x6f, 0xe1, 0x6d, 0xed, 0x1a, 0xd6, 0x5d, 0xd6, 0xc3, 0x22, 0xe1, 0xb5, 0xb0, 0x78, 0x9e, 0x8d, 0x3f, 0x8b, 0xf4, 0xc6, 0xb3, 0xc2, 0x32, 0xd2, 0x74, 0xf3, 0x64, 0x91, 0x75, 0x7d, 0xa9, 0xb0, 0x54, 0xe4, 0xbb, 0x88, 0xa0, 0xf5, 0x11, 0x91, 0xfe, 0xae, 0x08, 0x86, 0x33, 0x6a, 0x32, 0xf2, 0xc2, 0x40, 0x93, 0x9b, 0x5a, 0x2b, 0x6e, 0x0d, 0x09, 0x6b, 0xbe, 0x1e, 0x37, 0x89, 0xe0, 0xb7, 0x22, 0x52, 0x20, 0x0b, 0x93, 0xfa, 0x0f, 0x88, 0x9c, 0x5e, 0x19, 0x6e, 0xc1, 0x2f, 0xf1, 0xf6, 0xe2, 0xf9, 0xd4, 0xa2, 0xfc, 0x54, 0x31, 0xce, 0xe4, 0xb2, 0x86, 0xe9, 0xc4, 0x6e, 0xc6, 0x65, 0xc9, 0xf3, 0x64, 0xc1, 0xbb, 0x3f, 0xae, 0x59, 0x19, 0xeb, 0xf0, 0xae, 0x62, 0x12, 0x29, 0x9a, 0x92, 0x77, 0x46, 0x46, 0xf7, 0xda, 0x6d, 0x65, 0x22, 0x4f, 0x94, 0x06, 0x5e, 0xd3, 0x44, 0x62, 0x72, 0x76, 0xd2, 0x3e, 0x8d, 0xde, 0x3b, 0x1d, 0x02, 0x43, 0x64, 0xea, 0xad, 0xe4, 0xee, 0x5c, 0xb1, 0xb3, 0x0d, 0x9b, 0xba, 0x75, 0x65, 0x39, 0xfc, 0x4e, 0x64, 0x05, 0xea, 0xc8, 0x04, 0xdd, 0xfe, 0xa4, 0x60, 0x7a, 0xa9, 0x32, 0xd6, 0xe2, 0xc3, 0x3a, 0x5f, 0x23, 0xe4, 0xf8, 0x20, 0xee, 0x4c, 0xde, 0xf5, 0x16, 0xf2, 0xd7, 0x95, 0xf1, 0x8c, 0x06, 0x79, 0x1a, 0x3c, 0xcb, 0x5b, 0x17, 0xed, 0x42, 0xc1, 0xb7, 0xef, 0x33, 0x94, 0x05, 0xac, 0x17, 0xa9, 0xf3, 0xa3, 0x44, 0x24, 0xdb, 0x8a, 0x7e, 0xb1, 0x48, 0xab, 0xc5, 0xbd, 0x41, 0xeb, 0x5d, 0x74, 0xda, 0xcf, 0xea, 0xe2, 
	0xf7, 0x44, 0x9b, 0x71, 0x88, 0x6c, 0xc1, 0xa9, 0x62, 0x31, 0xee, 0x12, 0xf9, 0xac, 0xd5, 0xc2, 0xc2, 0x6e, 0x13, 0x99, 0xde, 0xd3, 0x8b, 0x71, 0x56, 0x2b, 0xdf, 0xad, 0xb5, 0x16, 0x99, 0x36, 0x42, 0x4f, 0x25, 0xb7, 0xa2, 0x6f, 0x9c, 0x5b, 0xfe, 0x31, 0x4d, 0xa5, 0x7b, 0x90, 0x50, 0x5e, 0x2e, 0x5c, 0xd7, 0xfd, 0xda, 0xdf, 0x55, 0x6c, 0x14, 0x3b, 0xe7, 0x48, 0xcd, 0xee, 0xbd, 0x0c, 0x6b, 0xf0, 0x66, 0x91, 0xf7, 0xba, 0x45, 0xec, 0xb6, 0x55, 0x62, 0x6d, 0x2f, 0x10, 0x59, 0x86, 0x7b, 0x85, 0x62, 0x06, 0xcf, 0xc9, 0x76, 0x2c, 0xeb, 0xda, 0xa2, 0xd1, 0x31, 0x22, 0x65, 0x30, 0x5e, 0xb8, 0xad, 0xfb, 0x44, 0x74, 0xda, 0x57, 0x22, 0x40, 0x1f, 0x3e, 0xa4, 0x71, 0x19, 0xf4, 0x60, 0x49, 0xbd, 0x3b, 0xf0, 0xde, 0xa2, 0xbc, 0x41, 0x79, 0x94, 0x5e, 0x15, 0xbe, 0xf6, 0x26, 0x91, 0xda, 0x19, 0x2f, 0xa2, 0xff, 0x7f, 0x16, 0x13, 0x1b, 0x5f, 0xf4, 0x93, 0x29, 0xcf, 0xab, 0x6d, 0x16, 0x77, 0x3b, 0x93, 0x0a, 0x99, 0x06, 0x53, 0x42, 0x19, 0x96, 0xf7, 0x0d, 0xe1, 0x26, 0x37, 0x08, 0xf7, 0xb8, 0x50, 0xcc, 0x7d, 0xb2, 0x50, 0xea, 0x3a, 0xfc, 0x15, 0xb7, 0x2b, 0x9f, 0x7f, 0xd9, 0x1c, 0x7e, 0x80, 0x5f, 0x89, 0x1d, 0x3e, 0x41, 0x2c, 0xfe, 0x63, 0xc5, 0xf7, 0x73, 0x8b, 0x31, 0xd6, 0xd5, 0x1b, 0xfc, 0x17, 0x10, 0xb7, 0xda, 0x4f, 0x4c, 0xfa, 0x0d, 0xd7, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

//------------------------------------------------------------------------------

inline cBitmap* NEW_CHAI3D_WHITE_LOGO()
{
    cImagePtr img = cImage::create();
    cLoadPNG(img->getImage(), CHAI3D_LOGO_WHITE_BYTEARRAY, sizeof(CHAI3D_LOGO_WHITE_BYTEARRAY));

    cBitmap* bitmap = new cBitmap();
    bitmap->loadFromImage(img);
    bitmap->setLocalPos(15,15);

    return (bitmap);
}

inline cBitmap* NEW_CHAI3D_BLACK_LOGO()
{
    cImagePtr img = cImage::create();
    cLoadPNG(img->getImage(), CHAI3D_LOGO_BLACK_BYTEARRAY, sizeof(CHAI3D_LOGO_BLACK_BYTEARRAY));

    cBitmap* bitmap = new cBitmap();
    bitmap->loadFromImage(img);
    bitmap->setLocalPos(15,15);

    return (bitmap);
}

//------------------------------------------------------------------------------
} // namespace chai3d
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------

