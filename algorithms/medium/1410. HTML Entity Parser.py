# 1410. HTML Entity Parser

# Runtime: 52 ms, faster than 91.08% of Python3 online submissions for HTML Entity Parser.
# Memory Usage: 14.4 MB, less than 100.00% of Python3 online submissions for HTML Entity Parser.

class Solution:
    def entityParser(self, text: str) -> str:
        return text.replace('&quot;', '"').replace('&apos;', "'").replace('&gt;', '>').replace('&lt;', '<').replace('&frasl;', '/').replace('&amp;', '&')