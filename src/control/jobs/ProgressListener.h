/*
 * Xournal++
 *
 * Interface for progress state
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

class ProgressListener {
public:
    virtual void setMaximumState(int64_t max) = 0;
    virtual void setCurrentState(int64_t state) = 0;

    virtual ~ProgressListener(){};
};

class DummyProgressListener: public ProgressListener {
public:
    virtual void setMaximumState(int64_t max){};
    virtual void setCurrentState(int64_t state){};

    virtual ~DummyProgressListener(){};
};
