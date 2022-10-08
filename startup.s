// .syntax unified
// 	.cpu cortex-m3
// 	.fpu softvfp
// 	.thumb
.global _Reset
_Reset:
 ldr sp, =stack_top
 BL _start
 B .
 