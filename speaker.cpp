#include "speaker.h"

Speaker::Speaker()
{
    connect(this, &QTextToSpeech::stateChanged, this, &Speaker::StateChanged);
    this->SpeakerState = Speaker::Idle;
    this->Delay = 0;
    this->FirstSentence = "";
    this->SecondSentence ="";
    this->Timer.setSingleShot(true);
}

void Speaker::SpeakWithDelay(QString FirstSentence, QString secondSentence, int delay)
{
    if (this->SpeakerState != Speaker::Idle)
        return;

    this->FirstSentence = FirstSentence;
    this->SecondSentence = secondSentence;
    this->Delay = delay;

    this->SpeakerState = Speaker::SpeakingFirst;
    this->say(this->FirstSentence);
}

void Speaker::StateChanged(QTextToSpeech::State state)
{
    if (state == QTextToSpeech::Speaking)
        return;
    else if (state == QTextToSpeech::Ready) {
        if (this->SpeakerState == Speaker::SpeakingFirst) {
            if (this->Timer.isActive())
                this->Timer.stop();

            this->SpeakerState = Speaker::SpeakingSecond;
            this->Timer.singleShot(this->Delay, this, & Speaker::SpeakSecondSentence);
        }

        else if (this->SpeakerState == Speaker::SpeakingSecond) {
            this->SpeakerState = Speaker::Idle;
            emit SpeakDone();
            return;
        }
    }
    else {
        if (this->Timer.isActive())
            this->Timer.stop();
        this->SpeakerState = Speaker::Idle;
        emit SpeakError();
    }
}

void Speaker::SpeakSecondSentence()
{
    this->say(this->SecondSentence);
}
