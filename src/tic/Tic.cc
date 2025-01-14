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

#include "Tic.h"
#include "../message/TicMessage_m.h"

Define_Module(Tic);

void Tic::initialize() {
    // TODO To Complete
}

TicMessage* Tic::createNewMessage() {
    delaySignal = registerSignal("delaySignal");
    TicMessage* message = new TicMessage();
    int dest = par("dest").intValue();
    while(dest == this->getIndex()) {
        dest = par("dest").intValue();
    }
    message->setCreationTime(simTime());
    message->setSrc(this->getIndex());
    message->setDest(dest);
    return message;
}

void Tic::sendMessage(TicMessage* message, bool isOptimized) {
    int dist = abs(message->getDest() - message->getSrc());
    if(isOptimized && (std::min(numTics - dist, dist) >= (numTics / 4))) {
        send(message, "routGate$o");
    } else  {
        int outGate = 0;
        if((message->getDest() - message->getSrc() + numTics) % numTics > (numTics / 2)) {
            outGate = 0;
        } else {
            outGate = 1;
        }
        send(message, "peerGate$o", outGate);
    }
}

void Tic::handleMessage(cMessage *msg) {
    // TODO To Complete
}

void Tic::finish() {
    if(sendTimer.isScheduled()) {
        cancelEvent(&sendTimer);
    }
}
