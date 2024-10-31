# Audio Effects Description and Usage

### 1. **Chorus Effect**
**Description**: The chorus effect creates a richer, fuller sound by simulating the effect of multiple voices or instruments playing the same part. This is achieved by slightly delaying and modulating the input signal to create the illusion of multiple sources.

```xml
<score bpm="120" beatspermeasure="4">
    <effects>
        <chorus id="chorus1" rate="1.5" amount="0.5" phase="0" channelOffset="0.25" mix="0.5" delay="0.01"/>
    </effects>
    <instrument instrument="ToneInstrument" effect="chorus1">
        <note measure="0" beat="1" duration="2.0" freq="440"/>
    </instrument>
</score>

```

### 2. **Flange Effect**
**Description**: The flange effect creates a swooshing or jet-like sound by mixing the input signal with a delayed copy of itself. The delay time is varied, creating a sweeping effect as the signals interfere with each other.

```xml
<score bpm="120" beatspermeasure="4">
    <effects>
        <flange id="flange1" rate="0.25" amount="1" phase="0" feedback="0.5" mix="0.5"/>
    </effects>
    <instrument instrument="ToneInstrument" effect="flange1">
        <note measure="0" beat="1" duration="2.0" freq="440"/> 
    </instrument>
</score>

```

### 3. **Noise Gate Effect**
**Description**: The noise gate effect reduces or eliminates background noise by muting the input signal when it falls below a certain threshold. It allows sound to pass only when the input level exceeds the threshold, effectively "gating" the noise.

```xml
<score bpm="120" beatspermeasure="4">
    <effects>
        <noiseGate id="noiseGate1" threshold="0.5" attack="0.1" hold="0.2" release="0.2"/>
    </effects>
    <instrument instrument="ToneInstrument" effect="noiseGate1">
        <note measure="0" beat="1" duration="2.0" freq="440"/>
    </instrument>
</score>

```

### 4. **Compression Effect**
**Description**: The compressor effect controls the dynamic range of the audio signal, making loud sounds quieter and quiet sounds louder. It works by reducing the gain of the signal when it exceeds a certain threshold, creating a more balanced sound.

```xml
<score bpm="120" beatspermeasure="4">
    <effects>
        <compressor id="compressor1" threshold="0.5" ratio="4.0" attack="0.1" release="0.2" isUpwards="false"/>
    </effects>
    <instrument instrument="ToneInstrument" effect="compressor1">
        <note measure="0" beat="1" duration="2.0" freq="440"/> <!-- A4 -->
    </instrument>
</score>

```
