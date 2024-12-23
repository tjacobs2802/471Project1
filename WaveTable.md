# WaveTable Synthesizer
Made by **Aidan Baird**

 **Wave Playback on Demand**: 
   - Generates audio when an XML request specifies notes for the "wavetable" instrument.

 **AR Envelope Generation**: 
   - Utilizes the AR class to modify sound sources for attack and release. 
   - Supports two Wavetable/Sample synthesis instruments: one with samples ≤ 4410 frames, the other with samples > 1 second.

 **Wavetable Synthesis**: 
   - Employs short audio recordings of sound waveforms from real instruments or generated mathematically. 
   - Provides five or more waveforms available for playback as directed by the sequencer.

Key features include:

- **Attack and Sustain Waves + Loop**: I have an envelope generator with attack and release settings using the m_ar object. The Start function configures the attack and release times by setting    parameters in m_ar, and Generate calls m_ar.Generate() to apply the envelope to each generated sample. The code includes logic to check LoopStart and LoopEnd times and reset the m_time and 
  m_frameIndex when reaching LoopEnd. Allowing a sample to repeat until the duration elapses.

-  **Pitch**: The pitch is handled via note identification and loading different samples for each note. The GetSample function uses the note’s name and octave to calculate a unique ID, which                   determines the sample loaded for each note.

-  **Glissando**: The Generate function calculates a glissando effect by smoothly interpolating between m_currentNote and m_nextNote, based on glissCoeff.
                  This interpolation adjusts pitch over time to create a gliding effect between notes.

## Sample Score
Here is a sample score to demonstrate the wavetable effects attack, release, and glissando.
```xml
<score bpm="120" beatspermeasure="4">
    <instrument instrument="WaveTable">

        <note measure="1" beat="1" duration="0.5" note="C4" attack="0.02" release="0.2"/>
        <note measure="1" beat="1.5" duration="0.5" note="G4" attack="0.02" release="0.2"/>
        <note measure="1" beat="2" duration="0.5" note="E4" attack="0.02" release="0.2"/>
        <note measure="1" beat="2.5" duration="1" note="D#4" attack="0.02" release="0.5"/>
        <note measure="1" beat="3.5" duration="0.5" note="A4" attack="0.02" release="0.2"/>
        <note measure="1" beat="4" duration="0.5" note="C#4" attack="0.02" release="0.2"/>

        <!-- gliss -->
        <note measure="7" beat="1" duration="1" note="C4" gliss="B4"/>
        <note measure="7" beat="2" duration="1" note="B4" gliss="C4"/>
        <note measure="7" beat="3" duration="1" note="C4" gliss="B4"/>
        <note measure="7" beat="4" duration="1" note="B4" gliss="A4"/>

        <note measure="8" beat="1" duration="1" note="D2" gliss="G4" attack="0.02" release="0.5"/>
        <note measure="8" beat="2" duration="0.5" note="C2" attack="0.02" release="0.2"/>
        <note measure="8" beat="2.5" duration="1" note="B2" gliss="C4" attack="0.02" release="0.5"/>
        <note measure="8" beat="3.5" duration="0.5" note="A2" attack="0.02" release="0.2"/>
        <note measure="8" beat="4" duration="0.5" note="G2" attack="0.02" release="0.2"/>
    </instrument>
</score>
```

**Final Recording:**  
Listen to the final recording here: [LINK](https://github.com/tjacobs2802/471Project1/blob/main/score/WAVs/WaveTable%20FINAL.wav)

