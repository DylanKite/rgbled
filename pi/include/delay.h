#ifndef DELAY_H
#define DELAY_H


class delay
{
public:
delay();
/**
 * Wait N CPU cycles (ARM CPU only)
 */
void wait_cycles(unsigned int n);

/**
 * Wait N microsec (ARM CPU only)
 */
void wait_msec(unsigned int n);

/**
 * Wait N microsec (with BCM System Timer)
 */
void wait_msec_st(unsigned int n);

/**
 * Wait N nanosec (ARM CPU only)
 */
void wait_nsec(unsigned int n);

private:
/**
 * Get System Timer's counter
 */
unsigned long get_system_timer();
};

#endif // DELAY_H
