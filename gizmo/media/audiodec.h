#ifndef __AUDIO_DECODER_H__
#define __AUDIO_DECODER_H__

#include "decoder.h"
#include "stream.h"
#include "avout.h"
#include <memory>

class Demux;
class AVOutput;


class AudioDec : public Decoder
{
	public:
		AudioDec();
		virtual ~AudioDec();

		virtual void start(const AVStream *stream);
		virtual void stop();

		void connectOutput(std::shared_ptr<AVOutput> output);

		virtual bool feed(const AVPacket *packet);
		virtual void flush();
		virtual void discontinuity();

	private:
		AVCodecContext *m_codecCtx;
		AVFrame *m_frame;
		std::shared_ptr<AVOutput> m_output;
		double m_timeBase;
};
#endif
