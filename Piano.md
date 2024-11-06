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


## Sample Score
Here is a sample score that was used to demo the piano's different capabilities
```xml
<?xml version="1.0" encoding="utf-8"?>
<score bpm="60" beatspermeasure="4">
    <instrument instrument="PianoInstrument">
        <!-- Measure 1: G major chord -->
        <note measure="1" beat="1" duration="4" piano="G3l" pedal="True"/>
        <note measure="1" beat="1" duration="4" piano="B3l" pedal="True"/>
        <note measure="1" beat="1" duration="4" piano="D4s" pedal="True"/>
        
        <!-- Measure 2: C major chord -->
        <note measure="2" beat="1" duration="4" piano="C3l" pedal="False"/>
        <note measure="2" beat="1" duration="4" piano="E3l" pedal="False"/>
        <note measure="2" beat="1" duration="4" piano="G3s" pedal="False"/>
        
        <!-- Measure 3: D major chord -->
        <note measure="3" beat="1" duration="4" piano="D3l" pedal="True"/>
        <note measure="3" beat="1" duration="4" piano="F#3l" pedal="True"/>
        <note measure="3" beat="1" duration="4" piano="A3s" pedal="True"/>
        
        <!-- Measure 4: G major chord (resolution) -->
        <note measure="4" beat="1" duration="3" piano="G3l" pedal="False"/>
        <note measure="4" beat="1" duration="3" piano="B3l" pedal="False"/>
        <note measure="4" beat="1" duration="3" piano="D4s" pedal="False"/>
    </instrument>
</score>


```
