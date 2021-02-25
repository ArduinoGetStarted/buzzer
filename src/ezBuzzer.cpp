/*
 * Copyright (c) 2019, ArduinoGetStarted.com. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * - Neither the name of the ArduinoGetStarted.com nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ARDUINOGETSTARTED.COM "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ARDUINOGETSTARTED.COM BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <ezBuzzer.h>

ezBuzzer::ezBuzzer(int pin) {
	_buzzerPin   = pin;
	_buzzerState = BUZZER_IDLE;

	_delayTime = 0;
	_beepTime  = 0;

	_startTime = 0;

	_melody = 0;
	_noteDurations = 0;
	_melodyLength  = 0;
	_melodyIndex   = 0;
	_notePauseTime = 0;

	pinMode(_buzzerPin, OUTPUT);
}


void ezBuzzer::stop(void){
	noTone(_buzzerPin);
	digitalWrite(_buzzerPin, LOW);

	_buzzerState = BUZZER_IDLE;
}

void ezBuzzer::beep(unsigned long beepTime) {
	beep(beepTime, 0);
}

void ezBuzzer::beep(unsigned long beepTime, unsigned long delay) {
	_delayTime = delay;
	_beepTime  = beepTime;
	_buzzerState = BUZZER_BEEP_DELAY;
	_startTime = millis();
}

void ezBuzzer::playMelody(int *melody, int *noteDurations, int length) {
	_melody = melody;
	_noteDurations = noteDurations;
	_melodyLength  = length;
	_melodyIndex   = 0;
	_notePauseTime = 0;

	_buzzerState = BUZZER_MELODY;
	_startTime = millis();
}

int ezBuzzer::getState(void) {
	return _buzzerState;
}

void ezBuzzer::loop(void) {

	switch(_buzzerState) {
		case BUZZER_IDLE:
			break;

		case BUZZER_BEEP_DELAY:
			if ((unsigned long)(millis() - _startTime) >= _delayTime) {
				_buzzerState = BUZZER_BEEPING;
				_startTime = millis();

				digitalWrite(_buzzerPin, HIGH);
			}

			break;

		case BUZZER_BEEPING:
			if ((unsigned long)(millis() - _startTime) >= _beepTime) {
				_buzzerState = BUZZER_IDLE;
				digitalWrite(_buzzerPin, LOW);
			}

			break;

		case BUZZER_MELODY:
			if(_melodyIndex < _melodyLength) {
				if(!_notePauseTime) {
					// to calculate the note duration, take one second divided by the note type.
					//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
					int duration = 1000 / _noteDurations[_melodyIndex];
					tone(_buzzerPin, _melody[_melodyIndex], duration);

					// to distinguish the notes, set a minimum time between them.
					// the note's duration + 30% seems to work well:
					_notePauseTime = duration * 1.30;
					_startTime = millis();
				}

				if ((unsigned long)(millis() - _startTime) >= _notePauseTime) {
					noTone(_buzzerPin); // stop the tone playing:
					_notePauseTime = 0;
					_melodyIndex++; // play next node
				}
			} else {
				noTone(_buzzerPin);
				_buzzerState = BUZZER_IDLE;
			}

			break;

		default:
			break;
	}
}