# Drum Synthesizer
Owned and developed by: Gregory Lis

The Drum Synthesizer simulates the sounds of a basic drum kit, and has essential drum sounds like bass drum, snare drum, toms, and cymbals. This synthesizer uses noise generation and pitch manipulation for a sound. It supports four main features to enhance sound realism:

## 1.) Polyphony
Polyphony means that the synthesizer can play one or more note at a time

## 2.) Envelopes
I use the AR class to envelope the sound of the drums which helps taper off audio clicks and make it sound more realistic.

## 3.) Noise Generation
I use random noise for a sound called "synthetic" to make a drum sound from scratch.

## 4.) Swept Fundamentals
I also have added swept fundamentals to the synthetic drum to help make it sound more realistic.


## Sample Score
Here is a sample score that was used to demo the drums's different sounds
```xml
<?xml version="1.0" encoding="utf-8"?>
<score bpm="120" beatspermeasure="4">
   <instrument instrument="DrumInstrument">
      <!-- Kick Drum Notes -->
      <note measure="1" beat="1" duration="1.0" drum="kick1"/>  
      <note measure="1" beat="2" duration="1.0" drum="kick2"/>
      <note measure="1" beat="3" duration="1.0" drum="kick3"/>

      <!-- Snare Drum Notes -->
      <note measure="2" beat="1" duration="1.5" drum="snare1"/>  
      <note measure="2" beat="2" duration="1.5" drum="snare2"/>
      <note measure="2" beat="3" duration="1.5" drum="snare3"/>
      <note measure="1" beat="4" duration="1.0" drum="synthetic"/>

      <!-- Clap Notes -->
      <note measure="2" beat="4" duration="0.25" drum="clap1"/>
      <note measure="2" beat="4.5" duration="0.25" drum="clap2"/>
      <note measure="2" beat="4.75" duration="0.25" drum="clap3"/>
      <note measure="3" beat="1" duration="0.25" drum="clap4"/>

      <!-- High Hat Notes -->
      <note measure="3" beat="2" duration="0.5" drum="highhat1"/>
      <note measure="3" beat="3" duration="0.5" drum="highhat2"/>
      <note measure="3" beat="4" duration="0.5" drum="highhat3"/>
      <note measure="3" beat="4.5" duration="0.5" drum="highhat4"/>

      <!-- Tom Notes -->
      <note measure="4" beat="1" duration="1.0" drum="tom1"/>
      <note measure="4" beat="2" duration="1.0" drum="tom2"/>
      <note measure="4" beat="3" duration="1.0" drum="tom3"/>

      <!-- Cymbal Notes -->
      <note measure="4" beat="4" duration="1.5" drum="cymbal1"/>
      <note measure="5" beat="1" duration="1.5" drum="cymbal2"/>
      <note measure="5" beat="2" duration="1.5" drum="cymbal3"/>
   </instrument>
</score>


```

**Final Recording:**  
Listen to the final recording here: [LINK](https://github.com/tjacobs2802/471Project1/blob/06f3e0cb01dd8619b9ce6b207fefd96c9694540f/score/WAVs/drum.wav)
