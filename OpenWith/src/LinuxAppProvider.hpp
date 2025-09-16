#pragma once

#if defined (__linux__)

#include "AppProvider.hpp"
#include "common.hpp"
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>


// For sorting found applications
struct RankedCandidate {
	CandidateInfo info;
	int rank; // match rank (the lower the better)
	bool is_default = false;

	// Operator for std::sort
	bool operator<(const RankedCandidate& other) const {
		if (is_default != other.is_default) return is_default; // true (default app) comes first
		if (rank != other.rank) return rank < other.rank; // sort by rank
		return info.name < other.info.name; // secondary sort by name
	}
};

// For deduplication by executable file
inline bool operator==(const CandidateInfo& a, const CandidateInfo& b)
{
	return a.exec == b.exec;
}


struct Token
{
	std::wstring text;
	bool quoted;
	bool single_quoted;
};


class LinuxAppProvider : public AppProvider
{
public:
	std::wstring GetMimeType(const std::wstring& pathname) override;
	std::vector<CandidateInfo> GetAppCandidates(const std::wstring& pathname) override;
	std::wstring ConstructCommandLine(const CandidateInfo& candidate, const std::wstring& pathname) override;

private:
	static std::string GetDefaultApp(const std::string& mime_type);
	static std::vector<std::string> GetXDGDataDirs();
	static std::vector<std::string> GetUserDirs();
	static std::vector<std::string> GetSystemDirs();
	static bool IsValidApplicationsDir(const std::string& path);
	static std::optional<CandidateInfo> ParseDesktopFile(const std::string& path);
	static std::optional<std::string> FindDesktopFileLocation(const std::string& desktopFile);
	static std::string GetLocalizedValue(const std::unordered_map<std::string, std::string>& values, const std::string& key);
	static std::vector<std::string> CollectAndPrioritizeMimeTypes(const std::wstring& pathname);
	static std::optional<int> GetBestMimeMatchRank(const std::string& desktop_pathname, const std::vector<std::string>& prioritized_mimes);
	static std::string RunCommandAndCaptureOutput(const std::string& cmd);
	static std::string Trim(std::string str);
	static bool IsDesktopWhitespace(wchar_t c);
	static std::vector<Token> TokenizeDesktopExec(const std::wstring& str);
	static std::wstring UndoEscapes(const Token& token);
	static std::string EscapePathForShell(const std::string& path);
	static bool ExpandFieldCodes(const CandidateInfo& candidate, const std::wstring& pathname, const std::wstring& unescaped, std::vector<std::wstring>& out_args);
	static std::wstring EscapeArg(const std::wstring& arg);
};

#endif
