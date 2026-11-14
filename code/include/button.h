#ifndef BUTTON_H
#define BUTTON_H

/* =====================================================================
 *  button.h — DISC1 blue USER button B1 (PA0).
 *
 *  On-board USER button, polled and debounced. Each press toggles the
 *  power-assist on/off (with gravity + friction comp).
 * =====================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

void buttonSetup(void);
void buttonPoll(void);

#ifdef __cplusplus
}
#endif

#endif /* BUTTON_H */