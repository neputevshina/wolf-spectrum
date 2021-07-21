#ifndef MIDIUTILS_HPP
#define MIDIUTILS_HPP

#include "src/DistrhoDefines.h"
#include <string>
#include <cmath>

START_NAMESPACE_DISTRHO

namespace wolf
{

static constexpr auto kNoteLabels = std::array{
    "C-0",
    "C#0",
    "D-0",
    "D#0",
    "E-0",
    "F-0",
    "F#0",
    "G-0",
    "G#0",
    "A-0",
    "A#0",
    "B-0",
    "C-1",
    "C#1",
    "D-1",
    "D#1",
    "E-1",
    "F-1",
    "F#1",
    "G-1",
    "G#1",
    "A-1",
    "A#1",
    "B-1",
    "C-2",
    "C#2",
    "D-2",
    "D#2",
    "E-2",
    "F-2",
    "F#2",
    "G-2",
    "G#2",
    "A-2",
    "A#2",
    "B-2",
    "C-3",
    "C#3",
    "D-3",
    "D#3",
    "E-3",
    "F-3",
    "F#3",
    "G-3",
    "G#3",
    "A-3",
    "A#3",
    "B-3",
    "C-4",
    "C#4",
    "D-4",
    "D#4",
    "E-4",
    "F-4",
    "F#4",
    "G-4",
    "G#4",
    "A-4",
    "A#4",
    "B-4",
    "C-5",
    "C#5",
    "D-5",
    "D#5",
    "E-5",
    "F-5",
    "F#5",
    "G-5",
    "G#5",
    "A-5",
    "A#5",
    "B-5",
    "C-6",
    "C#6",
    "D-6",
    "D#6",
    "E-6",
    "F-6",
    "F#6",
    "G-6",
    "G#6",
    "A-6",
    "A#6",
    "B-6",
    "C-7",
    "C#7",
    "D-7",
    "D#7",
    "E-7",
    "F-7",
    "F#7",
    "G-7",
    "G#7",
    "A-7",
    "A#7",
    "B-7",
    "C-8",
    "C#8",
    "D-8",
    "D#8",
    "E-8",
    "F-8",
    "F#8",
    "G-8",
    "G#8",
    "A-8",
    "A#8",
    "B-8",
    "C-9",
    "C#9",
    "D-9",
    "D#9",
    "E-9",
    "F-9",
    "F#9",
    "G-9",
    "G#9",
    "A-9",
    "A#9",
    "B-9",
    "C-10",
    "C#10",
    "D-10",
    "D#10",
    "E-10",
    "F-10",
    "F#10",
    "G-10",
    "G#10",
    "A-10",
    "A#10",
    "B-10",
    "C-11",
    "C#11",
    "D-11",
    "D#11",
    "E-11",
    "F-11",
    "F#11",
    "G-11",
    "G#11",
    "A-11",
    "A#11",
    "B-11",
    "C-12",
    "C#12",
    "D-12",
    "D#12",
    "E-12",
    "F-12",
    "F#12",
    "G-12",
    "G#12",
    "A-12",
    "A#12",
    "B-12",
    "C-13",
    "C#13",
    "D-13",
    "D#13",
    "E-13",
    "F-13",
    "F#13",
    "G-13",
    "G#13",
    "A-13",
    "A#13",
    "B-13",
};

std::string frequencyToNoteName(const float frequency)
{
    const auto midiNote = std::log(frequency / 440.f) / std::log(2) * 12 + 69;

    const uint noteIndex = std::round(midiNote);

    if (noteIndex < 0 || noteIndex >= kNoteLabels.size())
    {
        return "";
    }

    return kNoteLabels.at(noteIndex);
}

}; // namespace wolf

END_NAMESPACE_DISTRHO

#endif // MIDIUTILS_HPP
