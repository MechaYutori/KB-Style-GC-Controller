#include "keybind.h"

extern uint8_t CURSOL_MODE;
extern bool REVERSE_MODE;

void keybind(Report_t *report)
{
    switch (REVERSE_MODE)
    {
    case false:
        report->a = !((PINE >> 6) & 0b00000001);
        report->b = !((PIND >> 7) & 0b00000001);
        report->x = !((PINB >> 4) & 0b00000001);
        report->y = !((PINC >> 6) & 0b00000001);
        report->dup = !((PINF >> 6) & 0b00000001);
        report->ddown = !((PIND)&0b00000001);
        report->dleft = !((PIND >> 1) & 0b00000001);
        report->dright = !((PIND >> 4) & 0b00000001);
        report->start = !((PINB >> 5) & 0b00000001);
        report->z = !((PINF >> 7) & 0b00000001);
        break;

    case true:
        report->ddown = !((PINE >> 6) & 0b00000001);
        report->dleft = !((PIND >> 7) & 0b00000001);
        report->dright = !((PINB >> 4) & 0b00000001);
        report->dup = !((PINC >> 6) & 0b00000001);

        report->y = !((PINF >> 6) & 0b00000001);
        report->a = !((PIND)&0b00000001);
        report->x = !((PIND >> 1) & 0b00000001);
        report->b = !((PIND >> 4) & 0b00000001);

        report->start = !((PINB >> 5) & 0b00000001);
        report->z = !((PINF >> 7) & 0b00000001);
        break;
    }

    report->xAxis = 128;
    report->yAxis = 128;
    report->cxAxis = 128;
    report->cyAxis = 128;

    if (report->a && report->z && report->start)
    {
        if (report->dleft)
        {
            CURSOL_MODE = 1;
        }
        else if (report->dright)
        {
            CURSOL_MODE = 2;
        }
        else if (report->ddown)
        {
            CURSOL_MODE = 0;
        }
        else if (report->dup)
        {
            REVERSE_MODE = !REVERSE_MODE;
        }
    }

    switch (CURSOL_MODE)
    {
    case 0:
        if (report->dleft && report->dright)
        {
            report->dleft = false;
            report->dright = false;
        }
        if (report->dup && report->ddown)
        {
            report->dup = false;
            report->ddown = false;
        }
        break;

    case 1:
        report->xAxis = 128;
        report->yAxis = 128;
        if (report->dleft && !(report->dright))
        {
            report->xAxis = 0;
        }
        if (!(report->dleft) && report->dright)
        {
            report->xAxis = 255;
        }
        if (report->dup && !(report->ddown))
        {
            report->yAxis = 255;
        }
        if (!(report->dup) && report->ddown)
        {
            report->yAxis = 0;
        }
        report->dleft = false;
        report->dright = false;
        report->dup = false;
        report->ddown = false;
        break;

    case 2:
        report->cxAxis = 128;
        report->cyAxis = 128;
        if (report->dleft && !(report->dright))
        {
            report->cxAxis = 0;
        }
        if (!(report->dleft) && report->dright)
        {
            report->cxAxis = 255;
        }
        if (report->dup && !(report->ddown))
        {
            report->cyAxis = 255;
        }
        if (!(report->dup) && report->ddown)
        {
            report->cyAxis = 0;
        }
        report->dleft = false;
        report->dright = false;
        report->dup = false;
        report->ddown = false;
        break;
    }
}