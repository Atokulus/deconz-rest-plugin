/*
 * Copyright (c) 2021 dresden elektronik ingenieurtechnik gmbh.
 * All rights reserved.
 *
 * The software in this package is published under the terms of the BSD
 * style license a copy of which has been included with this distribution in
 * the LICENSE.txt file.
 *
 */

#ifndef DEVICE_ACCESS_FN_H
#define DEVICE_ACCESS_FN_H

#include <QString>
#include <QVariant>
#include <vector>

class Resource;
class ResourceItem;

namespace deCONZ {
    class ApsController;
    class ApsDataIndication;
    class ZclFrame;
}

struct DA_ReadResult
{
    bool isEnqueued = false;
    quint8 apsReqId = 0;
    quint8 sequenceNumber = 0;
};

typedef bool (*ParseFunction_t)(Resource *r, ResourceItem *item, const deCONZ::ApsDataIndication &ind, const deCONZ::ZclFrame &zclFrame);
typedef bool (*ReadFunction_t)(const Resource *r, const ResourceItem *item, deCONZ::ApsController *apsCtrl, DA_ReadResult *result);
typedef bool (*WriteFunction_t)(const Resource *r, const ResourceItem *item, deCONZ::ApsController *apsCtrl);

ParseFunction_t DA_GetParseFunction(const std::vector<QVariant> &params);
ReadFunction_t DA_GetReadFunction(const std::vector<QVariant> &params);
WriteFunction_t DA_GetWriteFunction(const std::vector<QVariant> &params);


#endif // DEVICE_ACCESS_FN_H
