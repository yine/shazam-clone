SHAZAM CLONE
=================

A shazam clone needs is made up of two programs:

**footprint-songs**: This program takes a folder directory containing several WAV files as an input, and stores a mapping of hashes from different points in time to the list of files where that hash is present.

**identify-song**: This takes a WAV file as an input, and then matches the song with a list of songs in the database.

### Pre-requisites

Intsall the lsndfile library. This is needed to read a .wav file into an array of integers

All wav files you use for this project must have:
- Sample rate of 22050 KHz
- Mono channel

### Compile and run the identify-audio program

```
make
./identify-audio [-cuda]
```
When it prompts you for an audio file, enter: "test/bjork.wav" or any other audio you want to identify.


### Compile and run the footprint-audio program

```
make
./footprint-audio [-cuda]
```

When it prompts you for the path of a music library, enter: "../../music-wav/"