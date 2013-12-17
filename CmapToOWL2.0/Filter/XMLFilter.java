package Filter;

import java.io.File;

import javax.swing.filechooser.FileFilter;

public class XMLFilter extends FileFilter {
		
		final static String XML = "xml";
		    
	    // Accept all directories and all xml files.
	    public boolean accept(File f) {

	        if (f.isDirectory()) {
	            return true;
	        }

	        String s = f.getName();
	        int i = s.lastIndexOf('.');

	        if (i > 0 &&  i < s.length() - 1) {
	            String extension = s.substring(i+1).toLowerCase();
	            if (XML.equals(extension)) {
	                    return true;
	            } else {
	                return false;
	            }
	        }

	        return true;
	    }
	    // The description of this filter
	    public String getDescription() {
	        return "Formato XML1.0";
	  }
}
