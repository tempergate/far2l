#pragma once

#if defined(__APPLE__)

#include "AppProvider.hpp"
#include <string>
#include <vector>

class MacOSAppProvider : public AppProvider
{
public:
	std::wstring GetMimeType(const std::wstring& pathname) override;
	std::vector<CandidateInfo> GetAppCandidates(const std::wstring& pathname) override;
	std::wstring ConstructCommandLine(const CandidateInfo& candidate, const std::wstring& pathname) override;
};

#endif
