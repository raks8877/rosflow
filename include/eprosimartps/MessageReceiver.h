/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of FastCdr is licensed to you under the terms described in the
 * EPROSIMARTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/*
 * MessageReceiver.h
 *
 *  Created on: Feb 20, 2014
 *      Author: Gonzalo Rodriguez Canosa
 *      email:  gonzalorodriguez@eprosima.com
 */



#ifndef MESSAGERECEIVER_H_
#define MESSAGERECEIVER_H_

#include "rtps_all.h"

namespace eprosima {
namespace rtps {

class MessageReceiver {
public:
	MessageReceiver();
	virtual ~MessageReceiver();
	void reset();
	/**
	 * Process a new CDR message.
	 * @param participantguidprefix Participant Guid Prefix
	 * @param address Address the message was received from
	 * @param data Pointer to data.
	 * @param length Length of the message in bytes.
	 */
	void processMsg(GuidPrefix_t participantguidprefix,
					octet*address,
			         void*data, short length);

	bool readEntityId(CDRMessage_t* msg,EntityId_t*id);
	bool readData(CDRMessage_t* msg,octet* o,uint16_t length);
	bool readDataReversed(CDRMessage_t* msg,octet* o,uint16_t length);
	bool readInt32(CDRMessage_t* msg,int32_t* lo);
	bool readUInt32(CDRMessage_t* msg,uint32_t* ulo);
	bool readSequenceNumber(CDRMessage_t* msg,SequenceNumber_t* sn);
	bool readInt16(CDRMessage_t* msg,int16_t* i16);
	bool readParameterList(CDRMessage_t* msg,ParameterList_t* list);
	bool readOctet(CDRMessage_t* msg,octet* o);

private:
	CDRMessage_t msg;
	ProtocolVersion_t sourceVersion;
	VendorId_t sourceVendorId;
	GuidPrefix_t sourceGuidPrefix;
	GuidPrefix_t destGuidPrefix;
	std::vector<Locator_t> unicastReplyLocatorList;
	std::vector<Locator_t> multicastReplyLocatorList;
	bool haveTimestamp;
	Time_t timestamp;

	/**
	 * Extract header from data stream.
	 * @param msg POinter to serialized Message
	 * @param H Pointer to header information.
	 * @return
	 */
	bool extractHeader(CDRMessage_t* msg, Header_t*H);





};

} /* namespace rtps */
} /* namespace eprosima */

#endif /* MESSAGERECEIVER_H_ */
