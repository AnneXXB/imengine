/*
 *  Copyright (c) 2016, https://github.com/nebula-im
 *  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CORE_ZPRORO_COMMAND_IDS_H_
#define CORE_ZPRORO_COMMAND_IDS_H_

// Frame层
const uint32_t FRAME_PROTO                      = 0x00000000;
const uint32_t FRAME_PING                       = 0x01000000;
const uint32_t FRAME_PONG                       = 0x02000000;
const uint32_t FRAME_DROP                       = 0x03000000;
const uint32_t FRAME_REDIRECT                   = 0x04000000;
const uint32_t FRAME_ACK                        = 0x05000000;
const uint32_t FRAME_HANDSHAKE                  = 0x06000000;
const uint32_t FRAME_HANDSHAKE_RESPONSE         = 0x07000000;
const uint32_t FRAME_MARS_SIGNAL                = 0x08000000;

// Package层
const uint32_t PACKAGE_AUTH_ID_INVALID          = 0x00010000;
const uint32_t PACKAGE_REQUEST_AUTH_ID          = 0x00020000;
const uint32_t PACKAGE_RESPONSE_AUTH_ID         = 0x00030000;
const uint32_t PACKAGE_REQUEST_START_AUTH       = 0x00040000;
const uint32_t PACKAGE_RESPONSE_START_AUTH      = 0x00050000;
const uint32_t PACKAGE_REQUEST_GET_SERVER_KEY   = 0x00060000;
const uint32_t PACKAGE_RESPONSE_GET_SERVER_KEY  = 0x00070000;
const uint32_t PACKAGE_REQUEST_DH               = 0x00080000;
const uint32_t PACKAGE_RESPONSE_DO_DH           = 0x00090000;
// SERVER_TO_SERVER_MESSAGE = 0x0A,
const uint32_t PACKAGE_ATTACH_DATA_MESSAGE      = 0x000A0000;
const uint32_t PACKAGE_CONTAINER                = 0x000B0000;
const uint32_t PACKAGE_MESSAGE_ACK              = 0x00100000;
const uint32_t PACKAGE_UNSENT_MESSAGE           = 0x00110000;
const uint32_t PACKAGE_UNSENT_RESPONSE          = 0x00120000;
const uint32_t PACKAGE_REQUEST_RESEND           = 0x00130000;
const uint32_t PACKAGE_NEW_SESSION              = 0x00140000;
const uint32_t PACKAGE_SESSION_HELLO            = 0x00150000;
const uint32_t PACKAGE_SESSION_LOST             = 0x00160000;
const uint32_t PACKAGE_RPC_REQUEST              = 0x00200000;
const uint32_t PACKAGE_RPC_OK                   = 0x00300000;
const uint32_t PACKAGE_RPC_ERROR                = 0x00310000;
const uint32_t PACKAGE_RPC_FLOOD_WAIT           = 0x00320000;
const uint32_t PACKAGE_RPC_INTERNAL_ERROR       = 0x00330000;
const uint32_t PACKAGE_PUSH                     = 0x00340000;

#endif

