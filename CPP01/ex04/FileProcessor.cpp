#include "FileProcessor.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

FileProcessor::FileProcessor(const std::string &filename, const std::string &s1,
	const std::string &s2) : filename(filename), s1(s1), s2(s2)
{
}

// Function to write the modified content to a new file
void FileProcessor::writeToFile(const std::string &modifiedContent) const
{
	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());

	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not create file " << outputFilename << std::endl;
		return ;
	}
	outputFile << modifiedContent;
	outputFile.close();
	std::cout << outputFilename << " is ready !!" << std::endl;
}

// Function to replace all occurrences of target with replacement in the given content
std::string FileProcessor::replaceString(const std::string &content) const
{
	std::string modifiedContent;
	size_t startPos = 0;
	size_t foundPos = content.find(s1, startPos);

	while (foundPos != std::string::npos)
	{
		modifiedContent.append(content, startPos, foundPos - startPos);
		modifiedContent.append(s2);
		startPos = foundPos + s1.length();
		foundPos = content.find(s1, startPos);
	}

	modifiedContent.append(content.substr(startPos));
	return (modifiedContent);
}

// Function to read the file and return its content as a string
std::string FileProcessor::readFile() const
{
	std::stringstream buffer;

	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Input file can not be opned." << std::endl;
		return ("");
	}
	buffer << inputFile.rdbuf();
	inputFile.close();
	return (buffer.str());
}

// The main function that coordinates file reading, string replacement,
void FileProcessor::processFile() const
{
	std::string content = readFile();
	if (content.empty())
		return ;
	std::string modifiedContent = replaceString(content);
	writeToFile(modifiedContent);
}
