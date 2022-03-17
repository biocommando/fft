This is a super simple FFT library written in C.

MIT license.

Example output when running the application in example.c:

```
> gcc example.c fft.c
> .\a.exe
Input = 3 sine waves at frequencies 0.1 f, 0.5 f, 1.5 f
Spectrum graph:
|________________________________|__ 0 dB
|________________________________|__ -5 dB
|_x___x_________x________________|__ -10 dB
|_x___x_________xx_______________|__ -15 dB
|_x___x_________xx_______________|__ -20 dB
|_x___x________xxxxx_____________|__ -25 dB
|_x__xxx______xxxxxxxxx__________|__ -30 dB
|_x__xxxx____xxxxxxxxxxxxxxxxxxxx|__ -35 dB
|_x_xxxxxx__xxxxxxxxxxxxxxxxxxxxx|__ -40 dB
|_x_xxxxxx__xxxxxxxxxxxxxxxxxxxxx|__ -45 dB
|_xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|__ -50 dB
|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|__ -55 dB
```