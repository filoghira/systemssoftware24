.global __aeabi_uidiv
__aeabi_uidiv:
    /* R0 = numerator, R1 = denominator */
    mov r2, r0              /* Copy numerator to r2 */
    mov r3, r1              /* Copy denominator to r3 */
    mov r0, #0              /* Initialize result in r0 */

divide_loop:
    cmp r2, r3              /* Compare numerator (r2) with denominator (r3) */
    blt done                /* If numerator < denominator, division is complete */
    sub r2, r2, r3          /* Subtract denominator from numerator */
    add r0, r0, #1          /* Increment result by 1 */
    b divide_loop           /* Repeat the loop */

done:
    bx lr                   /* Return result in r0 */