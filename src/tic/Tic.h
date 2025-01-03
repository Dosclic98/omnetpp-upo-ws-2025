//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef __OMNETPP_UPO_WS_2025_TIC_H_
#define __OMNETPP_UPO_WS_2025_TIC_H_

#include <omnetpp.h>

using namespace omnetpp;

class TicMessage;

class Tic : public cSimpleModule {
  private:
    int sendInterval;
    int numTics;
    bool isOptimized;
    cMessage sendTimer = cMessage("Send Message Timer");
    simsignal_t delaySignal;

  protected:
    virtual void initialize() override;
    virtual TicMessage* createNewMessage();
    virtual void sendMessage(TicMessage* message, bool isOptimized);
    virtual void finish() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif
