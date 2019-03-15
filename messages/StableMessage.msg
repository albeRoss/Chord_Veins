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

//
// TODO generated message class
//

cplusplus {{
#include "veins/modules/messages/WaveShortMessage_m.h"
}}
packet WaveShortMessage;

packet StableMessage extends WaveShortMessage{
    int countNode = 0;
    int firstNodeSender;
    int successor;
    bool isStable = false;
    int id = 0;
    string chordName = "";
    double startTime = 0.0;
    double ringDelay = 0.0;
}
