/*
 * Copyright (c) 2011-2014, fortiss GmbH.
 * Licensed under the Apache License, Version 2.0.
 *
 * Use, modification and distribution are subject to the terms specified
 * in the accompanying license file LICENSE.txt located at the root directory
 * of this software distribution. A copy is available at
 * http://chromosome.fortiss.org/.
 *
 * This file is part of CHROMOSOME.
 *
 * $Id: loginManagerManifest.c 7768 2014-03-11 15:08:26Z geisinger $
 */

/**
 * \file
 *         Defines function for creation of component type manifest
 *         for 'loginManager'.
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "xme/core/login/include-gen/loginManagerManifest.h"

#include "xme/core/log.h"
#include "xme/core/login/include-gen/loginManagerComponent.h"
#include "xme/core/login/include-gen/loginManagerComponentWrapper.h"
#include "xme/core/login/include-gen/loginManagerProcessLogoutNotificationFunction.h"
#include "xme/core/login/include-gen/loginManagerProcessLogoutNotificationFunctionWrapper.h"
#include "xme/core/login/include-gen/loginManagerProcessRequestFunction.h"
#include "xme/core/login/include-gen/loginManagerProcessRequestFunctionWrapper.h"
#include "xme/core/login/include-gen/loginManagerProcessResponseFunction.h"
#include "xme/core/login/include-gen/loginManagerProcessResponseFunctionWrapper.h"
#include "xme/hal/include/time.h"

/******************************************************************************/
/***   Implementation                                                       ***/
/******************************************************************************/
xme_status_t
xme_core_login_loginManager_manifest_createComponentTypeManifest
(
    xme_core_componentManifest_t* componentManifest
)
{
    XME_CHECK
    (
        NULL != componentManifest,
        XME_STATUS_INVALID_PARAMETER
    );

    (void)xme_hal_mem_set(componentManifest, 0U, sizeof(xme_core_componentManifest_t));

    componentManifest->componentType = (xme_core_componentType_t)10;
    componentManifest->componentWrapperInit = xme_core_login_loginManagerComponentWrapper_init;
    componentManifest->componentWrapperReceivePort = xme_core_login_loginManagerComponentWrapper_receivePort;
    componentManifest->componentWrapperFini = xme_core_login_loginManagerComponentWrapper_fini;
    componentManifest->componentInit = (xme_core_componentManifest_componentInit_t)xme_core_login_loginManagerComponent_init;
    (void)xme_hal_safeString_strncpy(componentManifest->name, "loginManager", sizeof(componentManifest->name));
    componentManifest->configStructSize = sizeof(xme_core_login_loginManagerComponent_config_t);

    {
        uint32_t functionArrayLength = sizeof(componentManifest->functionManifests) / sizeof(componentManifest->functionManifests[0]);

        // Function 'loginManagerProcessRequest'
        {
            if (0U >= functionArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (0U == functionArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'loginManager' defines more functions (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                       3,
                       functionArrayLength
                    );
                }
            }
            else
            {
                xme_core_functionManifest_t* functionManifest;
                
                functionManifest = &componentManifest->functionManifests[0];
                functionManifest->functionId = (xme_core_component_functionId_t)1;
                functionManifest->wcet = xme_hal_time_timeIntervalFromMilliseconds(100ull);
                functionManifest->alphaCurve.alphaCurve = 0;
                functionManifest->completion = true;
                functionManifest->requiredPortIndicesLength = 2;
                functionManifest->requiredPortIndices[0] = (xme_core_login_loginManagerComponentWrapper_internalPortId_t)XME_CORE_LOGIN_LOGINMANAGERCOMPONENTWRAPPER_PORT_INLOGINREQUEST;
                functionManifest->requiredPortIndices[1] = (xme_core_login_loginManagerComponentWrapper_internalPortId_t)XME_CORE_LOGIN_LOGINMANAGERCOMPONENTWRAPPER_PORT_OUTPNPLOGINREQUEST;
                functionManifest->optionalPortIndicesLength = 0;
                functionManifest->functionInit = (xme_core_exec_initCallback_t)xme_core_login_loginManagerProcessRequestFunction_init;
                functionManifest->functionFini = (xme_core_exec_finiCallback_t)xme_core_login_loginManagerProcessRequestFunction_fini;
                functionManifest->functionWrapperExecute = xme_core_login_loginManagerProcessRequestFunctionWrapper_execute;
            }
        }
        // Function 'loginManagerProcessResponse'
        {
            if (1U >= functionArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (1U == functionArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'loginManager' defines more functions (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                       3,
                       functionArrayLength
                    );
                }
            }
            else
            {
                xme_core_functionManifest_t* functionManifest;
                
                functionManifest = &componentManifest->functionManifests[1];
                functionManifest->functionId = (xme_core_component_functionId_t)2;
                functionManifest->wcet = xme_hal_time_timeIntervalFromMilliseconds(100ull);
                functionManifest->alphaCurve.alphaCurve = 0;
                functionManifest->completion = true;
                functionManifest->requiredPortIndicesLength = 2;
                functionManifest->requiredPortIndices[0] = (xme_core_login_loginManagerComponentWrapper_internalPortId_t)XME_CORE_LOGIN_LOGINMANAGERCOMPONENTWRAPPER_PORT_INPNPLOGINRESPONSE;
                functionManifest->requiredPortIndices[1] = (xme_core_login_loginManagerComponentWrapper_internalPortId_t)XME_CORE_LOGIN_LOGINMANAGERCOMPONENTWRAPPER_PORT_OUTLOGINRESPONSE;
                functionManifest->optionalPortIndicesLength = 0;
                functionManifest->functionInit = (xme_core_exec_initCallback_t)xme_core_login_loginManagerProcessResponseFunction_init;
                functionManifest->functionFini = (xme_core_exec_finiCallback_t)xme_core_login_loginManagerProcessResponseFunction_fini;
                functionManifest->functionWrapperExecute = xme_core_login_loginManagerProcessResponseFunctionWrapper_execute;
            }
        }
        // Function 'loginManagerProcessLogoutNotification'
        {
            if (2U >= functionArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (2U == functionArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'loginManager' defines more functions (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                       3,
                       functionArrayLength
                    );
                }
            }
            else
            {
                xme_core_functionManifest_t* functionManifest;
                
                functionManifest = &componentManifest->functionManifests[2];
                functionManifest->functionId = (xme_core_component_functionId_t)3;
                functionManifest->wcet = xme_hal_time_timeIntervalFromMilliseconds(10ull);
                functionManifest->alphaCurve.alphaCurve = 0;
                functionManifest->completion = true;
                functionManifest->requiredPortIndicesLength = 1;
                functionManifest->requiredPortIndices[0] = (xme_core_login_loginManagerComponentWrapper_internalPortId_t)XME_CORE_LOGIN_LOGINMANAGERCOMPONENTWRAPPER_PORT_INLOGOUTNOTIFICATION;
                functionManifest->optionalPortIndicesLength = 0;
                functionManifest->functionInit = (xme_core_exec_initCallback_t)xme_core_login_loginManagerProcessLogoutNotificationFunction_init;
                functionManifest->functionFini = (xme_core_exec_finiCallback_t)xme_core_login_loginManagerProcessLogoutNotificationFunction_fini;
                functionManifest->functionWrapperExecute = xme_core_login_loginManagerProcessLogoutNotificationFunctionWrapper_execute;
            }
        }
    }

    {
        uint32_t portArrayLength;
        portArrayLength = sizeof(componentManifest->portManifests) / sizeof(componentManifest->portManifests[0]);

        // Subscription 'inLoginRequest'
        {
            if (0 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (0 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'loginManager' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        5,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[0];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_SUBSCRIPTION;
                portManifest->topic = XME_CORE_TOPIC_LOGIN_LOGINREQUEST; 
                portManifest->lowerConnectionBound = 0u;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_UNBOUNDED;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
            }
        }
        // Subscription 'inPnPLoginResponse'
        {
            if (1 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (1 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'loginManager' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        5,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[1];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_SUBSCRIPTION;
                portManifest->topic = XME_CORE_TOPIC_LOGIN_PNPLOGINRESPONSE; 
                portManifest->lowerConnectionBound = 0u;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_UNBOUNDED;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
            }
        }
        // Subscription 'inLogoutNotification'
        {
            if (2 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (2 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'loginManager' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        5,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[2];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_SUBSCRIPTION;
                portManifest->topic = XME_CORE_TOPIC_PNP_LOGOUTNOTIFICATION; 
                portManifest->lowerConnectionBound = 0u;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_UNBOUNDED;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
            }
        }
        // Publication 'outPnPLoginRequest'
        {
            if (3 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (3 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'loginManager' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        5,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[3];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_PUBLICATION;
                portManifest->topic = XME_CORE_TOPIC_LOGIN_PNPLOGINREQUEST; 
                portManifest->lowerConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_INVALID;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_INVALID;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
                
            }
        }
        // Publication 'outLoginResponse'
        {
            if (4 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (4 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'loginManager' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        5,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[4];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_PUBLICATION;
                portManifest->topic = XME_CORE_TOPIC_LOGIN_LOGINRESPONSE; 
                portManifest->lowerConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_INVALID;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_INVALID;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
                
            }
        }
    }
    return XME_STATUS_SUCCESS;
}
