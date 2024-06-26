package zserio.extension.doc;

import java.io.File;

/**
 * Directory names created by this documentation extension.
 */
final class DocDirectories
{
    public static final String CONTENT_DIRECTORY = "content";
    public static final String CSS_DIRECTORY = "css";
    public static final String JS_DIRECTORY = "js";
    public static final String RESOURCES_DIRECTORY = "resources";

    public static final String PACKAGES_DIRECTORY = CONTENT_DIRECTORY + File.separator + "packages";
    public static final String DOC_RESOURCES_DIRECTORY = RESOURCES_DIRECTORY + File.separator + "doc";
    public static final String SYMBOL_COLLABORATION_DIRECTORY =
            RESOURCES_DIRECTORY + File.separator + "diagrams";
}
