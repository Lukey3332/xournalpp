/*
 * Xournal++
 *
 * Class to read audio data from an mp3 file
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <atomic>
#include <thread>
#include <utility>

#include <sndfile.h>

#include "AudioQueue.h"
#include "DeviceInfo.h"

struct VorbisProducer final {
    explicit VorbisProducer(AudioQueue<float>& audioQueue): audioQueue(audioQueue) {}

    bool start(const std::string& filename, uint64_t timestamp);
    void abort();
    void stop();
    void seek(int64_t seconds);

private:
    AudioQueue<float>& audioQueue;
    std::thread producerThread{};

    std::atomic<bool> stopProducer{false};
    std::atomic<int64_t> seekSeconds{0};
};
