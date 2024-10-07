#ifndef FILEPROCESSOR_HPP
# define FILEPROCESSOR_HPP

# include <string>

class FileProcessor
{
  private:
	std::string filename;
	std::string s1;
	std::string s2;

  public:
	FileProcessor(const std::string &filename, const std::string &s1,
		const std::string &s2);

	// Function to execute the file processing (read, replace, write)
	void processFile() const;

  private:
	// Helper function to read the file content
	std::string readFile() const;

	// Helper function to replace occurrences of target with replacement
	std::string replaceString(const std::string &content) const;

	// Helper function to write modified content to the output file
	void writeToFile(const std::string &modifiedContent) const;
};

#endif
