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

package omnetpp_upo_ws_2025.simulations;
import omnetpp_upo_ws_2025.tic.Tic;
import omnetpp_upo_ws_2025.router.Router;

network Network {
	parameters:
	    int numTics = default(20);
	    @statistic[delayStat](source=delaySignal; record=max,avg,vector);
	
	submodules:
	    tics[numTics]: Tic {
	    	numTics = parent.numTics;
	    };
	    router: Router {
	    	gateSize = parent.numTics;
	    };	    
	
	connections:
	    for i=0..numTics-1 {
	    	tics[i].peerGate[1] <--> {delay = 10ms;} <--> tics[(i+1)%numTics].peerGate[0];
	    	tics[i].routGate <--> {delay = 20ms;} <--> router.routGate[i];
	    }
}