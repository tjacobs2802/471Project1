# CSE 471 Project 1: Music Synthesizer
[Click here for our audio file: ***Sleigh Ride***](https://www.youtube.com/watch?v=dQw4w9WgXcQ)

## Group Members
* Trevor Jacobs - Piano Synthesizer
* Greg Lis - Drum Synthesizer
* Julia Bishop - Effects Component
* Aidan Baird - WaveTable synthesizer

## Navigation
* [Piano](./Piano.md)
* [Drums](./Drums.md)
* [Effects](./Effects.md)
* [WaveTable Synth](./WaveTable.md)

## Project Information
### Score File
 To display all of the individual parts of the Music Synthesizer, we made a feature piece: ***Sleigh Ride***. Each note
 is paird with an instrument, and each instrument might be paired with an effect. Here is the xml for our piece.

```xml

<score bpm="200" beatspermeasure="4">
    <effects>
        <chorus id="chorus1" rate="3" amount="3" phase="0.1" channelOffset="0.25" mix="1.0" delay="0.01"/>
        <noiseGate id="noiseGate1" threshold="0.1" attack="0.1" hold="0.2" release="0.2"/>
        <flange id="flange1" rate="0.25" amount="1" phase="0" feedback="0.5" mix="0.5"/>
        <compressor id="compressor1" threshold="0.1" ratio="6.0" attack="0.1" release="0.2" isUpwards="false"/>
    </effects>
    <instrument instrument="WaveTable" effect="compressor1">
        <note measure="1" beat="2" duration="0.5" note="F4"/>
        <note measure="1" beat="3" duration="0.5" note="C4" gliss="Bb4"/>
        <note measure="1" beat="3.5" duration="0.5" note="Bb4"/>
        <note measure="1" beat="4" duration="0.5" note="F4"/>

        <note measure="2" beat="1" duration="0.5" note="Bb4"/>
        <note measure="2" beat="2" duration="0.5" note="C4"/>

        <note measure="3" beat="2" duration="0.5" note="F4"/>
        <note measure="3" beat="3" duration="0.5" note="C4" gliss="Bb4"/>
        <note measure="3" beat="3.5" duration="0.5" note="Bb4"/>
        <note measure="3" beat="4" duration="0.5" note="F4"/>

        <note measure="4" beat="1" duration="0.5" note="Bb4"/>
        <note measure="4" beat="2" duration="0.5" note="C4"/>

        <note measure="5" beat="2" duration="0.5" note="F4"/>
        <note measure="5" beat="3" duration="0.5" note="C4" gliss="Bb4"/>
        <note measure="5" beat="3.5" duration="0.5" note="Bb4"/>
        <note measure="5" beat="4" duration="0.5" note="F4"/>

        <note measure="6" beat="1" duration="0.5" note="Bb4"/>
        <note measure="6" beat="2" duration="0.5" note="C4"/>
        <note measure="6" beat="2.5" duration="0.5" note="F4"/>
        <note measure="6" beat="3" duration="0.5" note="C4"/>
        <note measure="6" beat="4" duration="0.5" note="Bb4"/>
        <note measure="6" beat="4.5" duration="0.5" note="F4"/>

        <note measure="7" beat="1" duration="0.5" note="Bb4"/>
        <note measure="7" beat="1.5" duration="0.5" note="C4"/>
        <note measure="7" beat="2" duration="0.5" note="F4"/>
        <note measure="7" beat="3" duration="0.5" note="C4"/>
        <note measure="7" beat="4" duration="0.5" note="Bb4"/>

        <note measure="8" beat="1" duration="0.5" note="F4"/>

        

        <note measure="20" beat="2" duration="0.5" note="F4"/>
        <note measure="20" beat="3" duration="0.5" note="F4"/>
        <note measure="20" beat="4" duration="0.5" note="F4"/>

        <note measure="21" beat="1" duration="0.5" note="F4"/>
        <note measure="21" beat="2" duration="0.5" note="G4"/>
        <note measure="21" beat="3" duration="0.5" note="F4"/>
        <note measure="21" beat="3.5" duration="0.5" note="D4"/>
        <note measure="21" beat="4" duration="0.5" note="Bb3"/>

        <note measure="22" beat="1" duration="0.5" note="C4"/>
        <note measure="22" beat="2" duration="0.5" note="D4"/>
        <note measure="22" beat="3" duration="0.5" note="C4"/>
        <note measure="22" beat="3.5" duration="0.5" note="A3"/>
        <note measure="22" beat="4" duration="0.5" note="G3"/>

        <note measure="23" beat="1" duration="2" note="F3"/>

        <note measure="24" beat="2" duration="0.5" note="G3"/>
        <note measure="24" beat="2.5" duration="0.5" note="A3"/>
        <note measure="24" beat="3" duration="0.5" note="Bb3"/>
        <note measure="24" beat="3.5" duration="0.5" note="C4"/>
        <note measure="24" beat="4" duration="0.5" note="D4"/>
        <note measure="24" beat="4.5" duration="0.5" note="E4"/>

        <note measure="25" beat="1" duration="0.5" note="F4"/>
        <note measure="25" beat="2" duration="0.5" note="G4"/>
        <note measure="25" beat="3" duration="0.5" note="F4"/>
        <note measure="25" beat="3.5" duration="0.5" note="D4"/>
        <note measure="25" beat="4" duration="0.5" note="C4"/>
        <note measure="25" beat="4.5" duration="0.5" note="Bb3"/>

        <note measure="26" beat="1" duration="0.5" note="C4"/>
        <note measure="26" beat="2" duration="0.5" note="C4"/>
        <note measure="26" beat="2.5" duration="0.5" note="D4"/>
        <note measure="26" beat="3" duration="0.5" note="C4"/>
        <note measure="26" beat="3.5" duration="0.5" note="Bb3"/>
        <note measure="26" beat="4" duration="0.5" note="G3"/>

        <note measure="27" beat="1" duration="2" note="Bb3"/>

        <note measure="28" beat="4" duration="0.333" note="G4"/>
        <note measure="28" beat="4.333" duration="0.333" note="F#4"/>
        <note measure="28" beat="4.666" duration="0.333" note="G4"/>

        <note measure="29" beat="1" duration="0.5" note="D4"/>
        <note measure="29" beat="1" duration="0.5" note="B4"/>
        <note measure="29" beat="2" duration="0.333" note="G4"/>
        <note measure="29" beat="2.333" duration="0.333" note="F#4"/>
        <note measure="29" beat="2.666" duration="0.333" note="G4"/>
        <note measure="29" beat="3" duration="0.5" note="D4"/>
        <note measure="29" beat="3" duration="0.5" note="B4"/>
        <note measure="29" beat="4" duration="0.333" note="G4"/>
        <note measure="29" beat="4.333" duration="0.333" note="F#4"/>
        <note measure="29" beat="4.666" duration="0.333" note="G4"/>

        <note measure="30" beat="1" duration="0.5" note="D4"/>
        <note measure="30" beat="1" duration="0.5" note="B4"/>
        <note measure="30" beat="2" duration="0.5" note="E4"/>
        <note measure="30" beat="2" duration="0.5" note="G4"/>
        <note measure="30" beat="3" duration="2" note="C#4"/>
        <note measure="30" beat="3" duration="2" note="A4"/>

        <note measure="31" beat="2" duration="0.5" note="D4"/>
        <note measure="31" beat="2" duration="0.5" note="B4"/>
        <note measure="31" beat="3" duration="0.5" note="C#4"/>
        <note measure="31" beat="3" duration="0.5" note="A4"/>
        <note measure="31" beat="3.5" duration="0.5" note="A4"/>
        <note measure="31" beat="3.5" duration="0.5" note="F#4"/>
        <note measure="31" beat="4" duration="0.5" note="F#4"/>
        <note measure="31" beat="4" duration="0.5" note="D4"/>

        <note measure="32" beat="1" duration="2" note="B4"/>
        <note measure="32" beat="1" duration="2" note="F#4"/>

        <note measure="36" beat="4" duration="0.333" note="F4"/>
        <note measure="36" beat="4.333" duration="0.333" note="E4"/>
        <note measure="36" beat="4.666" duration="0.333" note="F4"/>

        <note measure="37" beat="1" duration="0.5" note="C4"/>
        <note measure="37" beat="1" duration="0.5" note="A4"/>
        <note measure="37" beat="2" duration="0.333" note="F4"/>
        <note measure="37" beat="2.333" duration="0.333" note="E4"/>
        <note measure="37" beat="2.666" duration="0.333" note="F4"/>
        <note measure="37" beat="3" duration="0.5" note="C4"/>
        <note measure="37" beat="3" duration="0.5" note="A4"/>
        <note measure="37" beat="4" duration="0.333" note="F4"/>
        <note measure="37" beat="4.333" duration="0.333" note="E4"/>
        <note measure="37" beat="4.666" duration="0.333" note="F4"/>

        <note measure="38" beat="1" duration="0.5" note="C4"/>
        <note measure="38" beat="1" duration="0.5" note="A4"/>
        <note measure="38" beat="2" duration="0.5" note="D4"/>
        <note measure="38" beat="2" duration="0.5" note="F4"/>
        <note measure="38" beat="3" duration="2" note="B4"/>
        <note measure="38" beat="3" duration="2" note="G4"/>

        <note measure="39" beat="2" duration="0.5" note="C4"/>
        <note measure="39" beat="2" duration="0.5" note="A4"/>
        <note measure="39" beat="3" duration="0.5" note="B4"/>
        <note measure="39" beat="3" duration="0.5" note="G4"/>
        <note measure="39" beat="3.5" duration="0.5" note="G4"/>
        <note measure="39" beat="3.5" duration="0.5" note="E4"/>
        <note measure="39" beat="4" duration="0.5" note="E4"/>
        <note measure="39" beat="4" duration="0.5" note="C4"/>

        <note measure="40" beat="1" duration="2" note="A4"/>
        <note measure="40" beat="1" duration="2" note="E4"/>

        <note measure="41" beat="2" duration="0.5" note="C4"/>
        <note measure="41" beat="3" duration="0.5" note="G4"/>
        <note measure="41" beat="3.5" duration="0.5" note="F4"/>
        <note measure="41" beat="4" duration="0.5" note="C4"/>

        <note measure="42" beat="1" duration="0.5" note="F4"/>
        <note measure="42" beat="2" duration="0.5" note="G4"/>
        <note measure="42" beat="2.5" duration="0.5" note="C4"/>
        <note measure="42" beat="3" duration="0.5" note="G4"/>
        <note measure="42" beat="4" duration="0.5" note="F4"/>
        <note measure="42" beat="4.5" duration="0.5" note="C4"/>

        <note measure="43" beat="1" duration="0.5" note="F4"/>
        <note measure="43" beat="1.5" duration="0.5" note="G4"/>
        <note measure="43" beat="2" duration="0.5" note="C4"/>
        <note measure="43" beat="3" duration="0.5" note="D4"/>
        <note measure="43" beat="4" duration="0.5" note="C4"/>

        <note measure="44" beat="1" duration="0.5" note="F4"/>
    </instrument>

    <instrument instrument="ToneInstrument" effect="chrous1">
        <note measure="1" beat="2" duration="1" note="F5"/>
        <note measure="1" beat="3" duration="0.5" note="C5"/>
        <note measure="1" beat="3.5" duration="0.5" note="Bb4"/>
        <note measure="1" beat="4" duration="1" note="F4"/>

        <note measure="2" beat="1" duration="1.0" note="Bb4"/>
        <note measure="2" beat="2" duration="1.0" note="C5"/>

        <note measure="3" beat="2" duration="1" note="F5"/>
        <note measure="3" beat="3" duration="0.5" note="C5"/>
        <note measure="3" beat="3.5" duration="0.5" note="Bb4"/>
        <note measure="3" beat="4" duration="1" note="F4"/>

        <note measure="4" beat="1" duration="1.0" note="Bb4"/>
        <note measure="4" beat="2" duration="1.0" note="C5"/>

        <note measure="5" beat="2" duration="1" note="F5"/>
        <note measure="5" beat="3" duration="0.5" note="C5"/>
        <note measure="5" beat="3.5" duration="0.5" note="Bb4"/>
        <note measure="5" beat="4" duration="1" note="F4"/>

        <note measure="6" beat="1" duration="1.0" note="Bb4"/>
        <note measure="6" beat="2" duration="0.5" note="C5"/>
        <note measure="6" beat="2.5" duration="0.5" note="F5"/>
        <note measure="6" beat="3" duration="1.0" note="C5"/>
        <note measure="6" beat="4" duration="0.5" note="Bb4"/>
        <note measure="6" beat="4.5" duration="0.5" note="F4"/>

        <note measure="7" beat="1" duration="0.5" note="Bb4"/>
        <note measure="7" beat="1.5" duration="0.5" note="C5"/>
        <note measure="7" beat="2" duration="1.0" note="F5"/>
        <note measure="7" beat="3" duration="1.0" note="C5"/>
        <note measure="7" beat="4" duration="1.0" note="Bb4"/>

        <note measure="8" beat="1" duration="0.5" note="F4"/>
        <note measure="8" beat="2" duration="0.5" note="F5"/>
        <note measure="8" beat="3" duration="0.5" note="F5"/>
        <note measure="8" beat="4" duration="0.5" note="F5"/>
        <note measure="8" beat="2" duration="0.5" note="Eb5"/>
        <note measure="8" beat="3" duration="0.5" note="Eb5"/>
        <note measure="8" beat="4" duration="0.5" note="Eb5"/>

        <note measure="9" beat="1" duration="0.5" note="F5"/>
        <note measure="9" beat="2" duration="0.5" note="C5"/>
        <note measure="9" beat="3" duration="0.5" note="C5"/>
        <note measure="9" beat="4" duration="0.5" note="C5"/>
        <note measure="9" beat="1" duration="0.5" note="D5"/>
        <note measure="9" beat="2" duration="0.5" note="F4"/>
        <note measure="9" beat="3" duration="0.5" note="F4"/>
        <note measure="9" beat="4" duration="0.5" note="F4"/>

        <note measure="10" beat="1" duration="0.5" note="C5"/>
        <note measure="10" beat="2" duration="0.5" note="F4"/>
        <note measure="10" beat="3" duration="0.5" note="F4"/>
        <note measure="10" beat="4" duration="0.5" note="F4"/>
        <note measure="10" beat="1" duration="0.5" note="F4"/>
        <note measure="10" beat="2" duration="0.5" note="D4"/>
        <note measure="10" beat="3" duration="0.5" note="D4"/>
        <note measure="10" beat="4" duration="0.5" note="D4"/>

        <note measure="11" beat="1" duration="0.5" note="F4"/>
        <note measure="11" beat="2" duration="0.5" note="C5"/>
        <note measure="11" beat="3" duration="0.5" note="C5"/>
        <note measure="11" beat="4" duration="0.5" note="C5"/>
        <note measure="11" beat="1" duration="0.5" note="D4"/>
        <note measure="11" beat="2" duration="0.5" note="F4"/>
        <note measure="11" beat="3" duration="0.5" note="F4"/>
        <note measure="11" beat="4" duration="0.5" note="F4"/>

        <note measure="12" beat="1" duration="0.5" note="C5"/>
        <note measure="12" beat="1" duration="0.5" note="F4"/>

        <note measure="12" beat="2" duration="0.5" note="F4"/>
        <note measure="12" beat="3" duration="0.5" note="F4"/>
        <note measure="12" beat="4" duration="0.5" note="F4"/>

        <note measure="13" beat="1" duration="0.5" note="F4"/>
        <note measure="13" beat="2" duration="0.5" note="G4"/>
        <note measure="13" beat="3" duration="0.5" note="F4"/>
        <note measure="13" beat="3.5" duration="0.5" note="D4"/>
        <note measure="13" beat="4" duration="0.5" note="Bb3"/>

        <note measure="14" beat="1" duration="0.5" note="C4"/>
        <note measure="14" beat="2" duration="0.5" note="D4"/>
        <note measure="14" beat="3" duration="0.5" note="C4"/>
        <note measure="14" beat="3.5" duration="0.5" note="A3"/>
        <note measure="14" beat="4" duration="0.5" note="G3"/>

        <note measure="15" beat="1" duration="4" note="F3"/>

        <note measure="16" beat="2" duration="0.5" note="G3"/>
        <note measure="16" beat="2.5" duration="0.5" note="A3"/>
        <note measure="16" beat="3" duration="0.5" note="Bb3"/>
        <note measure="16" beat="3.5" duration="0.5" note="C4"/>
        <note measure="16" beat="4" duration="0.5" note="D4"/>
        <note measure="16" beat="4.5" duration="0.5" note="E4"/>

        <note measure="17" beat="1" duration="0.5" note="F4"/>
        <note measure="17" beat="2" duration="0.5" note="G4"/>
        <note measure="17" beat="3" duration="0.5" note="F4"/>
        <note measure="17" beat="3.5" duration="0.5" note="D4"/>
        <note measure="17" beat="4" duration="0.5" note="C4"/>
        <note measure="17" beat="4.5" duration="0.5" note="Bb3"/>

        <note measure="18" beat="1" duration="0.5" note="C4"/>
        <note measure="18" beat="2" duration="0.5" note="C4"/>
        <note measure="18" beat="2.5" duration="0.5" note="D4"/>
        <note measure="18" beat="3" duration="0.5" note="C4"/>
        <note measure="18" beat="3.5" duration="0.5" note="Bb3"/>
        <note measure="18" beat="4" duration="0.5" note="G3"/>

        <note measure="19" beat="1" duration="4" note="Bb3"/>

        <note measure="20" beat="2" duration="0.5" note="F4"/>
        <note measure="20" beat="3" duration="0.5" note="F4"/>
        <note measure="20" beat="4" duration="0.5" note="F4"/>

        <note measure="21" beat="1" duration="0.5" note="F4"/>
        <note measure="21" beat="2" duration="0.5" note="G4"/>
        <note measure="21" beat="3" duration="0.5" note="F4"/>
        <note measure="21" beat="3.5" duration="0.5" note="D4"/>
        <note measure="21" beat="4" duration="0.5" note="Bb3"/>

        <note measure="22" beat="1" duration="0.5" note="C4"/>
        <note measure="22" beat="2" duration="0.5" note="D4"/>
        <note measure="22" beat="3" duration="0.5" note="C4"/>
        <note measure="22" beat="3.5" duration="0.5" note="A3"/>
        <note measure="22" beat="4" duration="0.5" note="G3"/>

        <note measure="23" beat="1" duration="4" note="F3"/>

        <note measure="24" beat="2" duration="0.5" note="G3"/>
        <note measure="24" beat="2.5" duration="0.5" note="A3"/>
        <note measure="24" beat="3" duration="0.5" note="Bb3"/>
        <note measure="24" beat="3.5" duration="0.5" note="C4"/>
        <note measure="24" beat="4" duration="0.5" note="D4"/>
        <note measure="24" beat="4.5" duration="0.5" note="E4"/>

        <note measure="25" beat="1" duration="0.5" note="F4"/>
        <note measure="25" beat="2" duration="0.5" note="G4"/>
        <note measure="25" beat="3" duration="0.5" note="F4"/>
        <note measure="25" beat="3.5" duration="0.5" note="D4"/>
        <note measure="25" beat="4" duration="0.5" note="C4"/>
        <note measure="25" beat="4.5" duration="0.5" note="Bb3"/>

        <note measure="26" beat="1" duration="0.5" note="C4"/>
        <note measure="26" beat="2" duration="0.5" note="C4"/>
        <note measure="26" beat="2.5" duration="0.5" note="D4"/>
        <note measure="26" beat="3" duration="0.5" note="C4"/>
        <note measure="26" beat="3.5" duration="0.5" note="Bb3"/>
        <note measure="26" beat="4" duration="0.5" note="G3"/>

        <note measure="27" beat="1" duration="4" note="Bb3"/>

        <note measure="28" beat="4" duration="0.333" note="G4"/>
        <note measure="28" beat="4.333" duration="0.333" note="F#4"/>
        <note measure="28" beat="4.666" duration="0.333" note="G4"/>

        <note measure="29" beat="1" duration="0.5" note="D5"/>
        <note measure="29" beat="1" duration="0.5" note="B4"/>
        <note measure="29" beat="2" duration="0.333" note="G4"/>
        <note measure="29" beat="2.333" duration="0.333" note="F#4"/>
        <note measure="29" beat="2.666" duration="0.333" note="G4"/>
        <note measure="29" beat="3" duration="0.5" note="D5"/>
        <note measure="29" beat="3" duration="0.5" note="B4"/>
        <note measure="29" beat="4" duration="0.333" note="G4"/>
        <note measure="29" beat="4.333" duration="0.333" note="F#4"/>
        <note measure="29" beat="4.666" duration="0.333" note="G4"/>

        <note measure="30" beat="1" duration="0.5" note="D5"/>
        <note measure="30" beat="1" duration="0.5" note="B4"/>
        <note measure="30" beat="2" duration="0.5" note="E5"/>
        <note measure="30" beat="2" duration="0.5" note="G4"/>
        <note measure="30" beat="3" duration="2" note="C#5"/>
        <note measure="30" beat="3" duration="2" note="A4"/>

        <note measure="31" beat="2" duration="0.5" note="D5"/>
        <note measure="31" beat="2" duration="0.5" note="B4"/>
        <note measure="31" beat="3" duration="0.5" note="C#5"/>
        <note measure="31" beat="3" duration="0.5" note="A4"/>
        <note measure="31" beat="3.5" duration="0.5" note="A4"/>
        <note measure="31" beat="3.5" duration="0.5" note="F#4"/>
        <note measure="31" beat="4" duration="0.5" note="F#4"/>
        <note measure="31" beat="4" duration="0.5" note="D4"/>

        <note measure="32" beat="1" duration="4" note="B4"/>
        <note measure="32" beat="1" duration="4" note="F#4"/>

        <note measure="33" beat="2" duration="1" note="C#5"/>
        <note measure="33" beat="2" duration="1" note="E4"/>
        <note measure="33" beat="3" duration="0.5" note="B4"/>
        <note measure="33" beat="3" duration="0.5" note="G4"/>
        <note measure="33" beat="3.5" duration="0.5" note="G4"/>
        <note measure="33" beat="3.5" duration="0.5" note="E4"/>
        <note measure="33" beat="4" duration="0.5" note="E4"/>
        <note measure="33" beat="4" duration="0.5" note="B3"/>
        <note measure="33" beat="4.5" duration="0.5" note="G4"/>
        <note measure="33" beat="4.5" duration="0.5" note="E4"/>

        <note measure="34" beat="1" duration="1" note="B4"/>
        <note measure="34" beat="1" duration="1" note="G4"/>
        <note measure="34" beat="2" duration="1" note="D5"/>
        <note measure="34" beat="2" duration="1" note="B4"/>
        <note measure="34" beat="3" duration="1" note="C#5"/>
        <note measure="34" beat="3" duration="1" note="A4"/>
        <note measure="34" beat="4" duration="1" note="E5"/>
        <note measure="34" beat="4" duration="1" note="G4"/>

        <note measure="35" beat="1" duration="6" note="A4"/>
        <note measure="35" beat="1" duration="6" note="F#4"/>

        <note measure="36" beat="4" duration="0.333" note="F4"/>
        <note measure="36" beat="4.333" duration="0.333" note="E4"/>
        <note measure="36" beat="4.666" duration="0.333" note="F4"/>

        <note measure="37" beat="1" duration="0.5" note="C5"/>
        <note measure="37" beat="1" duration="0.5" note="A4"/>
        <note measure="37" beat="2" duration="0.333" note="F4"/>
        <note measure="37" beat="2.333" duration="0.333" note="E4"/>
        <note measure="37" beat="2.666" duration="0.333" note="F4"/>
        <note measure="37" beat="3" duration="0.5" note="C5"/>
        <note measure="37" beat="3" duration="0.5" note="A4"/>
        <note measure="37" beat="4" duration="0.333" note="F4"/>
        <note measure="37" beat="4.333" duration="0.333" note="E4"/>
        <note measure="37" beat="4.666" duration="0.333" note="F4"/>

        <note measure="38" beat="1" duration="0.5" note="C5"/>
        <note measure="38" beat="1" duration="0.5" note="A4"/>
        <note measure="38" beat="2" duration="0.5" note="D5"/>
        <note measure="38" beat="2" duration="0.5" note="F4"/>
        <note measure="38" beat="3" duration="2" note="B4"/>
        <note measure="38" beat="3" duration="2" note="G4"/>

        <note measure="39" beat="2" duration="0.5" note="C5"/>
        <note measure="39" beat="2" duration="0.5" note="A4"/>
        <note measure="39" beat="3" duration="0.5" note="B4"/>
        <note measure="39" beat="3" duration="0.5" note="G4"/>
        <note measure="39" beat="3.5" duration="0.5" note="G4"/>
        <note measure="39" beat="3.5" duration="0.5" note="E4"/>
        <note measure="39" beat="4" duration="0.5" note="E4"/>
        <note measure="39" beat="4" duration="0.5" note="C4"/>

        <note measure="40" beat="1" duration="4" note="A4"/>
        <note measure="40" beat="1" duration="4" note="E4"/>

        <note measure="41" beat="2" duration="1" note="C5"/>
        <note measure="41" beat="3" duration="0.5" note="G4"/>
        <note measure="41" beat="3.5" duration="0.5" note="F4"/>
        <note measure="41" beat="4" duration="1" note="C4"/>

        <note measure="42" beat="1" duration="1.0" note="F4"/>
        <note measure="42" beat="2" duration="0.5" note="G4"/>
        <note measure="42" beat="2.5" duration="0.5" note="C5"/>
        <note measure="42" beat="3" duration="1.0" note="G4"/>
        <note measure="42" beat="4" duration="0.5" note="F4"/>
        <note measure="42" beat="4.5" duration="0.5" note="C4"/>

        <note measure="43" beat="1" duration="0.5" note="F4"/>
        <note measure="43" beat="1.5" duration="0.5" note="G4"/>
        <note measure="43" beat="2" duration="1.0" note="C5"/>
        <note measure="43" beat="3" duration="1.0" note="D5"/>
        <note measure="43" beat="4" duration="1.0" note="C5"/>

        <note measure="44" beat="1" duration="0.5" note="F4"/>
        <note measure="44" beat="2" duration="0.5" note="F5"/>
        <note measure="44" beat="3" duration="0.5" note="F5"/>
        <note measure="44" beat="4" duration="0.5" note="F5"/>
        <note measure="44" beat="2" duration="0.5" note="Eb5"/>
        <note measure="44" beat="3" duration="0.5" note="Eb5"/>
        <note measure="44" beat="4" duration="0.5" note="Eb5"/>

        <note measure="45" beat="1" duration="0.5" note="F5"/>
        <note measure="45" beat="2" duration="0.5" note="G5"/>
        <note measure="45" beat="3" duration="0.5" note="F5"/>
        <note measure="45" beat="1" duration="0.5" note="Eb5"/>
        <note measure="45" beat="3" duration="0.5" note="Eb5"/>
        <note measure="45" beat="3.5" duration="0.5" note="D5"/>
        <note measure="45" beat="4.0" duration="0.5" note="Bb4"/>

        <note measure="46" beat="1.0" duration="4" note="D5"/>
        <note measure="46" beat="1.0" duration="4" note="Bb4"/>

        <note measure="47" beat="1" duration="0.5" note="Bb4"/>
        <note measure="47" beat="2" duration="0.5" note="C5"/>
        <note measure="47" beat="3" duration="0.5" note="Bb4"/>
        <note measure="47" beat="1" duration="0.5" note="Eb5"/>
        <note measure="47" beat="3" duration="0.5" note="Eb5"/>
        <note measure="47" beat="3.5" duration="0.5" note="G4"/>
        <note measure="47" beat="4.0" duration="0.5" note="Eb4"/>

        <note measure="48" beat="1.0" duration="4" note="F4"/>
        <note measure="48" beat="1.0" duration="4" note="Bb4"/>

        <note measure="49" beat="1.0" duration="1" note="F4"/>
        <note measure="49" beat="1.0" duration="1" note="Bb4"/>
        <note measure="49" beat="2.0" duration="1" note="F4"/>
        <note measure="49" beat="3.0" duration="1" note="G4"/>
        <note measure="49" beat="4.0" duration="1" note="A4"/>

        <note measure="50" beat="1.0" duration="1" note="F4"/>
        <note measure="50" beat="1.0" duration="1" note="Bb4"/>
        <note measure="50" beat="2.0" duration="1" note="F4"/>
        <note measure="50" beat="2.0" duration="1" note="Bb4"/>
        <note measure="50" beat="4.0" duration="1" note="F4"/>
        <note measure="50" beat="4.0" duration="1" note="Bb4"/>

        <note measure="51" beat="1.0" duration="4" note="F4"/>
        <note measure="51" beat="1.0" duration="4" note="Bb4"/>

    </instrument>
    <instrument instrument="ToneInstrument" effect="flange1">
        <note measure="51" beat="1.0" duration="4" note="F4"/>
        <note measure="51" beat="1.0" duration="4" note="Bb4"/>

    </instrument>
    <instrument instrument="PianoInstrument" effect="noiseGate1">

        <note measure="0" beat="4.75" duration="5" note="D3#s" pedal="True"/>
        <note measure="0" beat="4.75" duration="5" note="G2s" pedal="True"/>

        <note measure="2" beat="1.75" duration="1" note="D3#s" pedal="False"/>
        <note measure="2" beat="2.75" duration="1" note="D3#s" pedal="False"/>
        <note measure="2" beat="3.75" duration="1" note="C3s" pedal="False"/>
        <note measure="2" beat="1.75" duration="1" note="G2s" pedal="False"/>
        <note measure="2" beat="2.75" duration="1" note="G2s" pedal="False"/>
        <note measure="2" beat="3.75" duration="1" note="C3s" pedal="False"/>

        <note measure="2" beat="4.75" duration="5" note="D3#s" pedal="True"/>
        <note measure="2" beat="4.75" duration="5" note="G2s" pedal="True"/>

        <note measure="4" beat="1.75" duration="1" note="D3#s" pedal="False"/>
        <note measure="4" beat="2.75" duration="1" note="D3#s" pedal="False"/>
        <note measure="4" beat="3.75" duration="1" note="C3s" pedal="False"/>
        <note measure="4" beat="1.75" duration="1" note="G2s" pedal="False"/>
        <note measure="4" beat="2.75" duration="1" note="G2s" pedal="False"/>
        <note measure="4" beat="3.75" duration="1" note="C3s" pedal="False"/>

        <note measure="4" beat="4.75" duration="3" note="D3#s" pedal="False"/>
        <note measure="4" beat="4.75" duration="3" note="G2s" pedal="False"/>

        <note measure="5" beat="3.75" duration="0.5" note="C3s" pedal="False"/>
        <note measure="5" beat="4.25" duration="0.5" note="C3s" pedal="False"/>
    
        <note measure="6" beat="1" duration="2.75" note="D3#s" pedal="False"/>
        <note measure="6" beat="1" duration="2.75" note="G2s" pedal="False"/>

        <note measure="6" beat="3.75" duration="0.5" note="C3s" pedal="False"/>
        <note measure="6" beat="4.25" duration="0.5" note="C3s" pedal="False"/>

        <note measure="6" beat="4.75" duration="0.5" note="D3#s" pedal="False"/>
        <note measure="6" beat="4.75" duration="0.5" note="G2s" pedal="False"/>

        <note measure="7" beat="1.25" duration="0.5" note="D3#s" pedal="False"/>
        <note measure="7" beat="1.75" duration="1.0" note="D3#s" pedal="False"/>
        <note measure="7" beat="1.25" duration="0.5" note="G2s" pedal="False"/>
        <note measure="7" beat="1.75" duration="1.0" note="G2s" pedal="False"/>
        <note measure="7" beat="2.75" duration="1.0" note="C3s" pedal="False"/>
        <note measure="7" beat="3.75" duration="1" note="D3#s" pedal="False"/>
        <note measure="7" beat="3.75" duration="1" note="G2s" pedal="False"/>

        <note measure="7" beat="4.75" duration="1" note="F3s" pedal="False"/>
        <note measure="7" beat="4.75" duration="1" note="A2#s" pedal="False"/>

        <note measure="12" beat="4.75" duration="2" note="A3s" pedal="False"/>
        <note measure="13" beat="2.75" duration="2" note="G3s" pedal="False"/>

        <note measure="13" beat="4.75" duration="2" note="A3#s" pedal="False"/>
        <note measure="14" beat="2.75" duration="2" note="A3s" pedal="False"/>

        <note measure="14" beat="4.75" duration="2" note="A3s" pedal="False"/>
        <note measure="15" beat="2.75" duration="2" note="G3s" pedal="False"/>

        <note measure="15" beat="4.75" duration="2" note="A3#s" pedal="False"/>
        <note measure="16" beat="2.75" duration="2" note="A3s" pedal="False"/>

        <note measure="16" beat="4.75" duration="2" note="A3s" pedal="False"/>
        <note measure="17" beat="2.75" duration="2" note="G3s" pedal="False"/>

        <note measure="17" beat="4.75" duration="2" note="A3#s" pedal="False"/>
        <note measure="18" beat="2.75" duration="2" note="A3s" pedal="False"/>

        <note measure="18" beat="4.75" duration="1" note="A3#s" pedal="False"/>
        <note measure="19" beat="1.75" duration="1" note="F3s" pedal="False"/>
        <note measure="19" beat="2.75" duration="1" note="G3l" pedal="False"/>
        <note measure="19" beat="3.75" duration="1" note="F3s" pedal="False"/>

        <note measure="19" beat="4.75" duration="1" note="A3l" pedal="False"/>
        <note measure="20" beat="1.75" duration="1" note="F3s" pedal="False"/>
        <note measure="20" beat="2.75" duration="1" note="G3#l" pedal="False"/>
        <note measure="20" beat="3.75" duration="1" note="F3s" pedal="False"/>

        <note measure="20" beat="4.75" duration="2" note="A3s" pedal="False"/>
        <note measure="21" beat="2.75" duration="2" note="G3s" pedal="False"/>

        <note measure="21" beat="4.75" duration="2" note="A3#s" pedal="False"/>
        <note measure="22" beat="2.75" duration="2" note="A3s" pedal="False"/>

        <note measure="22" beat="4.75" duration="2" note="A3s" pedal="False"/>
        <note measure="23" beat="2.75" duration="2" note="G3s" pedal="False"/>

        <note measure="23" beat="4.75" duration="2" note="A3#s" pedal="False"/>
        <note measure="24" beat="2.75" duration="2" note="A3s" pedal="False"/>

        <note measure="24" beat="4.75" duration="2" note="A3s" pedal="False"/>
        <note measure="25" beat="2.75" duration="2" note="G3s" pedal="False"/>

        <note measure="25" beat="4.75" duration="2" note="A3#s" pedal="False"/>
        <note measure="26" beat="2.75" duration="2" note="A3s" pedal="False"/>

        <note measure="26" beat="4.75" duration="4" note="A3#s" pedal="False"/>

        <note measure="27" beat="1.75" duration="1" note="G4l" pedal="False"/>
        <note measure="27" beat="2.75" duration="2" note="F4s" pedal="False"/>
        <note measure="27" beat="1.75" duration="1" note="D4#l" pedal="False"/>
        <note measure="27" beat="2.75" duration="2" note="D4s" pedal="False"/>

        <note measure="27" beat="4.75" duration="1" note="G4l" pedal="False"/>
        <note measure="28" beat="1.75" duration="2" note="F4s" pedal="False"/>
        <note measure="27" beat="4.75" duration="1" note="D4#l" pedal="False"/>
        <note measure="28" beat="1.75" duration="2" note="D4s" pedal="False"/>

        <note measure="28" beat="4.75" duration="5" note="G3s" pedal="True"/>

        <note measure="30" beat="1.75" duration="1" note="B3s" pedal="False"/>
        <note measure="30" beat="2.75" duration="1" note="A3s" pedal="False"/>
        <note measure="30" beat="3.75" duration="1" note="G3s" pedal="False"/>

        <note measure="30" beat="4.75" duration="5" note="F3#s" pedal="True"/>

        <note measure="32" beat="1.75" duration="1" note="D3s" pedal="False"/>
        <note measure="32" beat="2.75" duration="1" note="F3#s" pedal="False"/>
        <note measure="32" beat="3.75" duration="1" note="B3s" pedal="False"/>

        <note measure="32" beat="4.75" duration="5" note="G3s" pedal="True"/>

        <note measure="34" beat="1.75" duration="1" note="B3s" pedal="False"/>
        <note measure="34" beat="2.75" duration="1" note="A3s" pedal="False"/>
        <note measure="34" beat="3.75" duration="1" note="G3s" pedal="False"/>

        <note measure="34" beat="4.75" duration="5" note="F3#s" pedal="True"/>

        <note measure="36" beat="4.75" duration="5" note="F3s" pedal="True"/>

        <note measure="38" beat="1.75" duration="1" note="A3s" pedal="False"/>
        <note measure="38" beat="2.75" duration="1" note="B3s" pedal="False"/>
        <note measure="38" beat="3.75" duration="1" note="F4#s" pedal="False"/>

        <note measure="38" beat="4.75" duration="5" note="E4s" pedal="True"/>

        <note measure="40" beat="1.75" duration="1" note="G3s" pedal="False"/>
        <note measure="40" beat="2.75" duration="1" note="A3s" pedal="False"/>
        <note measure="40" beat="3.75" duration="1" note="E4s" pedal="False"/>

        <note measure="40" beat="4.75" duration="8" note="G3l" pedal="True"/>

        <note measure="42" beat="4.75" duration="2" note="A3l" pedal="False"/>
        <note measure="43" beat="2.75" duration="2" note="A3#l" pedal="False"/>

        <note measure="43" beat="4.75" duration="1" note="A3#l" pedal="False"/>

        <note measure="45" beat="4.75" duration="4" note="D5l" pedal="False"/>
        <note measure="45" beat="4.75" duration="4" note="A4#l" pedal="False"/>

        <note measure="47" beat="4.75" duration="4" note="D5l" pedal="False"/>
        <note measure="47" beat="4.75" duration="4" note="A4#l" pedal="False"/>

        <note measure="50" beat="4.75" duration="4" note="D5l" pedal="False"/>
        <note measure="50" beat="4.75" duration="4" note="A4#l" pedal="False"/>

    </instrument>

    <instrument instrument="DrumInstrument" effect="noiseGate1">
        <note measure="1" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="1" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="1" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="1" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="2" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="2" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="2" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="2" beat="4" duration="0.5" drum="highhat1"/>
        <note measure="2" beat="3" duration="1" drum="synthetic"/>
        <note measure="2" beat="4" duration="1" drum="synthetic"/>

        <note measure="3" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="3" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="3" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="3" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="4" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="4" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="4" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="4" beat="4" duration="0.5" drum="highhat1"/>
        <note measure="4" beat="3" duration="1" drum="synthetic"/>
        <note measure="4" beat="4" duration="1" drum="synthetic"/>

        <note measure="5" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="5" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="5" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="5" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="6" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="6" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="6" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="6" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="7" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="7" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="7" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="7" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="8" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="8" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="8" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="8" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="9" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="9" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="10" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="10" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="11" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="11" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="12" beat="1" duration="0.5" drum="highhat1"/>

        <note measure="13" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="13" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="13" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="13" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="14" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="14" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="14" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="14" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="15" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="15" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="15" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="15" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="16" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="16" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="16" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="16" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="17" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="17" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="17" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="17" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="18" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="18" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="18" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="18" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="19" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="19" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="19" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="19" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="20" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="20" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="20" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="20" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="21" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="21" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="21" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="21" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="22" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="22" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="22" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="22" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="23" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="23" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="23" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="23" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="24" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="24" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="24" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="24" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="25" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="25" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="25" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="25" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="26" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="26" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="26" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="26" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="27" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="27" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="28" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="28" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="28" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="29" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="29" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="29" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="29" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="30" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="30" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="30" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="30" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="31" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="31" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="31" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="31" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="32" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="32" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="32" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="32" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="33" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="33" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="33" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="33" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="34" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="34" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="34" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="34" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="35" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="35" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="36" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="36" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="36" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="37" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="37" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="37" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="37" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="38" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="38" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="38" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="38" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="39" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="39" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="39" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="39" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="40" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="40" beat="2" duration="0.5" drum="highhat1"/>
        <note measure="40" beat="3" duration="0.5" drum="highhat1"/>
        <note measure="40" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="41" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="41" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="42" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="42" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="43" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="43" beat="3" duration="0.5" drum="highhat1"/>

        <note measure="44" beat="1" duration="0.5" drum="highhat1"/>
        <note measure="44" beat="4" duration="0.5" drum="highhat1"/>

        <note measure="50" beat="3" duration="0.5" drum="highhat1"/>

    </instrument>
</score>
```
