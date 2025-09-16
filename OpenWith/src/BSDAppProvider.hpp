#pragma once

#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)

#include "AppProvider.hpp"
#include <string>
#include <vector>

class BSDAppProvider : public AppProvider
{
public:
	std::wstring GetMimeType(const std::wstring& pathname) override;
	std::vector<CandidateInfo> GetAppCandidates(const std::wstring& pathname) override;
	std::wstring ConstructCommandLine(const CandidateInfo& candidate, const std::wstring& pathname) override;
};

#endif
