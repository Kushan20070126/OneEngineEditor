#include "EditorException.h"
#include <sstream>


OneEngineException::OneEngineException( int line,const char* file ) noexcept
	:
	line( line ),
	file( file )
{}

const char* OneEngineException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* OneEngineException::GetType() const noexcept
{
	return "Chili Exception";
}

int OneEngineException::GetLine() const noexcept
{
	return line;
}

const std::string& OneEngineException::GetFile() const noexcept
{
	return file;
}

std::string OneEngineException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}