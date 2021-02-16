package zserio.extension.common;

import java.io.File;
import java.util.HashMap;
import java.util.Map;

import zserio.tools.ExtensionParameters;
import zserio.tools.ZserioToolPrinter;

/**
 * Helper class which manages all files generated by an extension.
 *
 * Output file manager provides logic which decides whether it's needed to regenerate each
 * particular file based on its timestamp.
 */
public class OutputFileManager
{
    /**
     * Constructor.
     *
     * @param extensionParameters Extension parameters.
     */
    public OutputFileManager(ExtensionParameters extensionParameters)
    {
        lastModifiedSourceTime = extensionParameters.getLastModifiedTime();
        ignoreTimestamps = extensionParameters.getIgnoreTimestamps();
    }

    /**
     * Prints report about output files.
     */
    public void printReport()
    {
        int generated = 0;
        int skipped = 0;

        for (Map.Entry<File, Boolean> entry : outputFiles.entrySet())
        {
            if (entry.getValue())
                generated++;
            else
                skipped++;
        }

        ZserioToolPrinter.printMessage("  Generated " + generated + " file" + (generated == 1 ? "" : "s")  +
                (skipped > 0 ? ", skipped " + skipped + " file" + (skipped == 1 ? "" : "s") : ""));
    }

    /**
     * Checks file's timestamps against timestamps of Zserio sources and resources (e.g. jar file).
     *
     * When the file is newer than Zserio sources and resources, then it's up to date and its generation
     * can be safely skipped, if any other circumstances (e.g. extension parameters) were not changed.
     * It's the responsibility of each extension to decide whether it's safe to skip the generation.
     *
     * @param outputFile Output file to check.
     *
     * @return True if the output file is newer than Zserio sources and resources, False otherwise.
     */
    public boolean checkTimestamps(File outputFile)
    {
        if (ignoreTimestamps || lastModifiedSourceTime == 0L)
            return false;

        return outputFile.lastModified() > lastModifiedSourceTime;
    }

    /**
     * Registers an output file.
     *
     * @param outputFile Output file to register.
     * @param generated True if file is newly generated, False if the file generation is skipped.
     *
     * @throws ZserioExtensionException if the outputFile is already registered.
     */
    public void registerOutputFile(File outputFile, boolean generated) throws ZserioExtensionException
    {
        if (outputFiles.put(outputFile, generated) != null)
        {
            throw new ZserioExtensionException(
                    "OutputFileManager: File '" + outputFile + "' already registered!");
        }
    }

    /**
     * Registers newly generated output file.
     *
     * Overloaded function provided for convenience.
     *
     * @param outputFile Output file to register.
     *
     * @throws ZserioExtensionException if the outputFile is already registered.
     */
    public void registerOutputFile(File outputFile) throws ZserioExtensionException
    {
        registerOutputFile(outputFile, true);
    }

    /**
     * Gets information about an output file.
     *
     * @param outputFile Output file to get info for.
     *
     * @return True if the file is being generated, False if it has been skipped and null if it's not yet
     *         registered.
     */
    public Boolean getOutputFileInfo(File outputFile)
    {
        return outputFiles.get(outputFile);
    }

    private final long lastModifiedSourceTime; // last modified time of Zserio sources and resources (e.g. jar)
    private final boolean ignoreTimestamps;
    private final Map<File, Boolean> outputFiles = new HashMap<File, Boolean>();
}
