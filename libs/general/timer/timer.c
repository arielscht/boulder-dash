
void timer_update(int *timer, int *frameCounter)
{
    if (*frameCounter % 60 == 0)
    {
        *timer += 1;
    }
}