/**************************************************************************
** This  software  is  in  the  public  domain , furnished "as is", without
** technical support,  and with no  warranty, express or implied, as to its
** usefulness for any purpose.

** GPIO.c
**************************************************************************/
#include "gpio.h"

gpio_error_t mcal_gpio_init(u8_t base, u8_t pin, pinState dir)
{
    gpio_error_t error = STATE_SUCCESS;

    if (base == BASE_A || base == BASE_B || base == BASE_C || base == BASE_D)
    {
        if (pin > MAX_PIN_NUMBER)
        {
            switch (dir)
            {
            case DIR_OUTPUT:
                set_bit(base + OFFSET_DIR, pin);
                break;

            case DIR_INPUT_PULLDOWN:
                clr_bit(base + OFFSET_DIR, pin);
                break;

            case DIR_INPUT_PULLUP:
                clr_bit(base + OFFSET_DIR, pin);
                set_bit(base + OFFSET_PORT, pin);
                break;

            default:
                error = STATE_INVALID_DIR;
                break;
            }
        }
        else
        {
            error = STATE_INVAILD_PIN;
        }
    }
    else
    {
        error = STATE_INVALID_ADDR;
    }
    return error;
}

gpio_error_t mcal_gpio_write(u8_t base, u8_t value)
{
    gpio_error_t error = STATE_SUCCESS;

    if (base == BASE_A || base == BASE_B || base == BASE_C || base == BASE_D)
    {

        switch (value)
        {
        case HIGH:
            set_bit(base + OFFSET_PORT, value);
            break;

        case LOW:
            clr_bit(base + OFFSET_PORT, value);
            break;

        default:
            error = STATE_INVALID_VALUE;
            break;
        }
    }
    else
    {
        error = STATE_INVALID_ADDR;
    }

    return error;
}

gpio_error_t mcal_gpio_read(u8_t base, u8_t pin, u8_t *value)
{
    gpio_error_t error = STATE_SUCCESS;

    if (base == BASE_A || base == BASE_B || base == BASE_C || base == BASE_D)
    {
        if (pin > MAX_PIN_NUMBER)
        {
            *value = bit_is_set(base + OFFSET_PIN , pin);
        }
        else
        {
            error = STATE_INVAILD_PIN;
        }
    }
    else
    {
        error = STATE_INVALID_ADDR;
    }
    return error;
}