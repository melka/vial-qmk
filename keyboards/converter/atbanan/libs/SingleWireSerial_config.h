#ifndef SingleWireSerial_config_h
#define SingleWireSerial_config_h

#define ICTIMER 1

#define TCCRA TCCR1A
#define TCCRB TCCR1B
#define TCCRC TCCR1C
#define TCNT TCNT1
#define OCRA OCR1A
#define ICR  ICR1
#define ICNC ICNC1

#define TIMSK TIMSK1
#define TIFR  TIFR1

#define TOV   TOV1
#define ICF   ICF1
#define ICIE  ICIE1
#define OCFA  OCF1A
#define CS1   CS11
#define CS0   CS10
#define ICES  ICES1
#define WGM2  WGM12
#define WGM3  WGM13
#define TIMER_CAPT_vect TIMER1_CAPT_vect

#define ICArduinoPin 4
#define ICDDR DDRD
#define ICPIN PIND
#define ICBIT PD4
#define OCArduinoPin 9
#define OCPORT PORTB
#define OCBIT  PB5

#endif
