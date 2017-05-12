//
// Created by usuryjskij on 10.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <sstream>
#include <regex>
#include <stdexcept>

namespace moviesubs{
    class MicroDvdSubtitles{
    public:
        MicroDvdSubtitles();
        ~MicroDvdSubtitles();
        void ShiftAllSubtitlesBy(int ms, int fps, std::stringstream *in,  std::stringstream *out);
    private:
        int sprawdz(std::string Kasia, int i);
        std::string zmien(std::string Kasia, int i, int offset);

    };

    class InvalidSubtitleLineFormat: public std::invalid_argument{
    public:
        InvalidSubtitleLineFormat(std::string in): invalid_argument{"InvalidSubtitleLineFormat"}{};
        ~InvalidSubtitleLineFormat();
    };

    class NegativeFrameAfterShift: public std::invalid_argument{
    public:
        NegativeFrameAfterShift(std::string in) : invalid_argument{"Negative frame"}{};
        ~NegativeFrameAfterShift();
    };

    class SubtitleEndBeforeStart: public std::invalid_argument{
    public:
        SubtitleEndBeforeStart(std::string in) :  invalid_argument{"At line 2: {260}{220}NEWLINE"}{}
        ~SubtitleEndBeforeStart();
        int LineAt() const;

    };
    class NegativeFrameRateThrowsIlegalArgument: public std::invalid_argument{
    public:
        NegativeFrameRateThrowsIlegalArgument(std::string in): invalid_argument{"Negative fps value"}{}
    };
}
#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
