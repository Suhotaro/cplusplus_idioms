// Stream.h
#ifndef STREAM_H
#define STREAM_H

struct Stream {
	Stream();
	~Stream();
};
extern Stream& stream; // global stream object

static struct StreamInitializer {
	StreamInitializer();
	~StreamInitializer();
} streamInitializer; // static initializer for every translation unit

#endif // STREAM_H