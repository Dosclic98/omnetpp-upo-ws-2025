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

package omnetpp_upo_ws_2025.tic;

simple Tic {
    parameters:
        int sendInterval @unit(ms) = default(500ms);
        int numTics = default(2);
        volatile int dest = default(intuniform(0, numTics-1));
        bool isOptimized = default(false);

		@signal[delaySignal](type=simtime_t);
		@statistic[delayStat](source=delaySignal; record=max,avg,vector,histogram);
        @display("i=block/routing");
    gates:
        inout peerGate[2];
        inout routGate;

}
