package zserio.runtime.validation;

/**
 * Validation timer used from validation code generated by Zserio.
 *
 * Validation timer calculates elapsed time in milliseconds.
 */
public final class ValidationTimer
{
    /**
     * Default constructor.
     */
    public ValidationTimer()
    {
        duration = 0;
    }

    /**
     * Starts measurement of time.
     */
    public void start()
    {
        startMilliseconds = System.currentTimeMillis();
    }

    /**
     * Stops measuremnt of time.
     */
    public void stop()
    {
        duration += System.currentTimeMillis() - startMilliseconds;
    }

    /**
     * Gets timer duration.
     *
     * @return Returns elapsed time in milliseconds.
     */
    public long getDuration()
    {
        return duration;
    }

    private long  startMilliseconds;
    private long  duration;
}
