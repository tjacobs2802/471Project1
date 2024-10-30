# CSE 471 Project 1: Music Synthesizer
[Click here for our audio file: ***Dazed and Confused***](https://www.youtube.com/watch?v=dQw4w9WgXcQ)

## Group Members
* Trevor Jacobs - Piano Synthesizer
* Greg Lis -
* Julia Bishop - Effects Component
* Aidan Baird - WaveTable synthesizer

## Navigation
* [Piano](./Piano.md)
* [WaveTable Synth](./WaveTable.md)
* Effects
*

## Project Information
### Score File
 To display all of the individual parts of the Music Synthesizer, we made a feature piece: ***Dazed and Confused***. Each note
 is paird with an instrument, and each instrument might be paired with an effect. Here is the xml for our piece.

```xml

<?xml version="1.0" encoding="utf-8"?>
<score bpm="120" beatspermeasure="2">
     <instrument instrument="ToneInstrument">
          <note measure="1" beat="2" duration="0.33" note="F4"/>
          <note measure="1" beat="2.33" duration="0.33" note="G4"/>
          <note measure="1" beat="2.6" duration="0.33" note="A4"/>

          <note measure="2" beat="1" duration="0.5" note="Bb4"/>
          <note measure="2" beat="1" duration="0.5" note="G4"/>
          <note measure="2" beat="1" duration="0.5" note="Eb4"/>

          <note measure="3" beat="1" duration="0.5" note="Bb4"/>
          <note measure="3" beat="1" duration="0.5" note="G4"/>
          <note measure="3" beat="1" duration="0.5" note="Eb4"/>

          <note measure="4" beat="1" duration="0.5" note="Bb4"/>
          <note measure="4" beat="1" duration="0.5" note="D4"/>
          <note measure="4" beat="1" duration="0.5" note="F4"/>

          <note measure="4" beat="2" duration="0.5" note="Bb4"/>
          <note measure="4" beat="2" duration="0.5" note="G4"/>
          <note measure="4" beat="2" duration="0.5" note="Eb4"/>

          <note measure="5" beat="1" duration="0.5" note="Bb4"/>
          <note measure="5" beat="1" duration="0.5" note="D4"/>
          <note measure="5" beat="1" duration="0.5" note="F4"/>

          <note measure="6" beat="1" duration="0.5" note="G4"/>
          <note measure="6" beat="1.5" duration="0.5" note="F#4"/>
          <note measure="6" beat="2" duration="0.5" note="G4"/>
          <note measure="6" beat="2.5" duration="0.5" note="G#4"/>

          <note measure="7" beat="1" duration="1" note="A4"/>
          <note measure="7" beat="2" duration="1" note="F4"/>

          <note measure="8" beat="1" duration="3" note="Bb4"/>
          <note measure="8" beat="1" duration="3" note="F4"/>
          <note measure="8" beat="1" duration="3" note="D4"/>
     </instrument>
</score>
```
