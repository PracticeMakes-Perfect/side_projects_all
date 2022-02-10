#include <stdio.h>

typedef enum {
	ST_RADIO,
	ST_CD
} STATES;

typedef enum {
	EVT_MODE,
	EVT_NEXT
} EVENTS;

EVENTS readEventFromMessageQueue(int);

EVENTS readEventFromMessageQueue (int i) {
	if (i % 2 == 0) {
		return EVT_MODE;
	} else {
		return EVT_NEXT;
	}
}

int main(int argc, char* argv) {
	STATES state = ST_RADIO;
	int stationNum = 0;
	int trackNum = 0;
	int i = 10;
	
	while (i > -1) {
		//block event here!
		EVENTS event = readEventFromMessageQueue(i);
		
		switch (state) {
			case ST_RADIO:
				printf("in ST_RADIO with i: %d\n", i);
				
				switch (event) {
					case EVT_MODE:
						printf("in EVT_MODE then change state to  ST_CD\n");
						state = ST_CD;
						
						break;
					case EVT_NEXT:
						printf("in EVT_NEXT with stationNum: %d\n", stationNum);
						++stationNum;
						
						break;
				}
				break;
			case ST_CD:
				printf("in ST_CD with i: %d\n", i);
				
				switch (event) {
					case EVT_MODE:
						printf("in EVT_MODE then change state to  ST_RADIO\n");
						state = ST_RADIO;
						
						break;
					case EVT_NEXT:
						printf("in EVT_NEXT with trackNum: %d\n", trackNum);
						++trackNum;
						
						break;
				}
				break;
		}
		
		--i;
	}
	
	return 0;
}