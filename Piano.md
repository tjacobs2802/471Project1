# Piano Synthesizer
Owned and developed by: **Trevor Jacobs**
One page for each component that describes the functioning of that component in detail.  
Indicate ownership of each component and what grading elements are supported.
The Piano Synthesizer, in essence, simulates the sound of an acoustic piano. 
It demonstrates all 88 keys of the standard piano. The synthesizer also has 5 different
customizations to it as well:

## 1.) Polyphony
Polyphony means that the synthesizer can play one or more note at a time

## 2.) Envelopes
Envelopes simulates what happens whne a key is released by not just cutting
off the sound, rather by dampening it.

## 3.) Pedal Simulation
An acoustic piano has a pedal. When pressed, the pedal allows you to play notes for their full duration. The score will determine if pedal is pressed.

## 4.) Pedal Noise
Like a real piano, the pedal makes a noise as it's pressed and released.

## 5.) Dynamics (basic and advanced)
The samples allow for the piano to be loud and soft, like an actual piano. The program implements how loud or soft notes are played based on the score.

```xml
<?xml version="1.0" encoding="utf-8"?>
<score bpm="60" beatspermeasure="4">
	<instrument instrument="PianoInstrument">
		<!-- Measure 1 -->
		<note measure="1" beat="1" duration="1.9" piano="110"/>
		<note measure="1" beat="1" duration="1.9" piano="175"/>
		<note measure="1" beat="3" duration="1.9" piano="74"/>
		
		<!-- Measure 2 -->
		<note measure="2" beat="1" duration="1.5" piano="152"/>
		<note measure="2" beat="2" duration="1.5" piano="65"/>
		<note measure="2" beat="3" duration="1.5" piano="180"/>
		<note measure="2" beat="4" duration="1.0" piano="25"/>
		
		<!-- Measure 3 -->
		<note measure="3" beat="1" duration="2.0" piano="92"/>
		<note measure="3" beat="3" duration="1.9" piano="128"/>
		<note measure="3" beat="3.5" duration="0.5" piano="156"/>
		<note measure="3" beat="4" duration="1.0" piano="51"/>
		
		<!-- Measure 4 -->
		<note measure="4" beat="1" duration="2.0" piano="10"/>
		<note measure="4" beat="2.5" duration="1.5" piano="190"/>
		<note measure="4" beat="3" duration="1.0" piano="75"/>
		<note measure="4" beat="4" duration="1.0" piano="140"/>
		
		<!-- Measure 5 -->
		<note measure="5" beat="1" duration="2.5" piano="56"/>
		<note measure="5" beat="3.5" duration="1.5" piano="160"/>
		<note measure="5" beat="4" duration="0.5" piano="95"/>
		<note measure="5" beat="4.5" duration="0.5" piano="35"/>
		
		<!-- Measure 6 - Ending -->
		<note measure="6" beat="1" duration="4.0" piano="111"/>
	</instrument>
</score>
```
