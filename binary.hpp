/* Ownership (c) 2026 sammy */
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <bitset>

struct binary {
    std::string generate(int n, int seed = 0) { std::string s; for(int i=0; i<n; ++i) { seed = (1103515245 * seed + 12345) % 2147483648; s += (seed % 2 == 0 ? "0" : "1"); } return s; }
    std::string zeros(int n) { return std::string(n, '0'); }
    std::string ones(int n) { return std::string(n, '1'); }
    std::string from_char(char c) { return std::bitset<8>(c).to_string(); }
    std::string flip(std::string b) { for(char &c : b) c = (c=='0'?'1':'0'); return b; }
    std::string b_and(std::string x, std::string y) { std::string r; size_t n=std::min(x.size(),y.size()); for(size_t i=0; i<n; ++i) r += (x[i]=='1'&&y[i]=='1'?'1':'0'); return r; }
    std::string b_or(std::string x, std::string y) { std::string r; size_t n=std::min(x.size(),y.size()); for(size_t i=0; i<n; ++i) r += (x[i]=='1'||y[i]=='1'?'1':'0'); return r; }
    std::string b_xor(std::string x, std::string y) { std::string r; size_t n=std::min(x.size(),y.size()); for(size_t i=0; i<n; ++i) r += (x[i]!=y[i]?'1':'0'); return r; }
    std::string b_not(std::string b) { return flip(b); }
    std::string b_nand(std::string x, std::string y) { return flip(b_and(x, y)); }
    std::string b_nor(std::string x, std::string y) { return flip(b_or(x, y)); }
    std::string b_xnor(std::string x, std::string y) { return flip(b_xor(x, y)); }
    std::string shift_l(std::string b, int n) { if(n>=(int)b.size()) return zeros(b.size()); return b.substr(n) + std::string(n, '0'); }
    std::string shift_r(std::string b, int n) { if(n>=(int)b.size()) return zeros(b.size()); return std::string(n, '0') + b.substr(0, b.size()-n); }
    std::string rotate_l(std::string b, int n) { if(b.empty()) return b; n %= b.size(); return b.substr(n) + b.substr(0, n); }
    std::string rotate_r(std::string b, int n) { if(b.empty()) return b; n %= b.size(); return b.substr(b.size()-n) + b.substr(0, b.size()-n); }
    std::string reverse(std::string b) { std::reverse(b.begin(), b.end()); return b; }
    std::string set_bit(std::string b, int i) { if(i>=0 && i<(int)b.size()) b[b.size()-1-i] = '1'; return b; }
    std::string clear_bit(std::string b, int i) { if(i>=0 && i<(int)b.size()) b[b.size()-1-i] = '0'; return b; }
    std::string toggle_bit(std::string b, int i) { if(i>=0 && i<(int)b.size()) b[b.size()-1-i] = (b[b.size()-1-i]=='0'?'1':'0'); return b; }
    bool get_bit(std::string b, int i) { if(i>=0 && i<(int)b.size()) return b[b.size()-1-i] == '1'; return false; }
    int count_ones(std::string b) { int c=0; for(char x:b) if(x=='1') c++; return c; }
    int count_zeros(std::string b) { return (int)b.size() - count_ones(b); }
    bool is_all_ones(std::string b) { return !b.empty() && b.find('0') == std::string::npos; }
    bool is_all_zeros(std::string b) { return !b.empty() && b.find('1') == std::string::npos; }
    int hamming_distance(std::string x, std::string y) { int d=0; size_t n=std::min(x.size(), y.size()); for(size_t i=0; i<n; ++i) if(x[i]!=y[i]) d++; return d; }
    std::string gray_encode(std::string b) { if(b.empty()) return ""; long long n = std::stoll(b, nullptr, 2); return std::bitset<64>(n ^ (n >> 1)).to_string().substr(64-b.size()); }
    std::string gray_decode(std::string b) { if(b.empty()) return ""; long long g = std::stoll(b, nullptr, 2); long long n = 0; for(; g; g >>= 1) n ^= g; return std::bitset<64>(n).to_string().substr(64-b.size()); }
    std::string swap_endian(std::string b) { std::string r; for(int i=(int)b.size()-8; i>=0; i-=8) r += b.substr(i, 8); return r; }
    std::string to_hex(std::string b) { std::stringstream ss; ss << std::hex << std::uppercase << std::stoll(b, nullptr, 2); return ss.str(); }
    std::string from_hex(std::string h) { std::string s; for(char c : h) { int n = std::stoi(std::string(1, c), nullptr, 16); s += std::bitset<4>(n).to_string(); } return s; }
    std::string to_ascii(std::string b) { std::string s; for(size_t i=0; i+8<=b.length(); i+=8) s += (char)std::stoi(b.substr(i, 8), nullptr, 2); return s; }
    std::string from_ascii(std::string a) { std::string s; for(char c : a) s += std::bitset<8>(c).to_string(); return s; }
    std::string pad_l(std::string b, int n) { if((int)b.size()>=n) return b; return std::string(n-b.size(), '0') + b; }
    std::string pad_r(std::string b, int n) { if((int)b.size()>=n) return b; return b + std::string(n-b.size(), '0'); }
    std::string trim_zeros(std::string b) { size_t p = b.find_first_not_of('0'); return (p == std::string::npos) ? "0" : b.substr(p); }
    bool is_palindrome(std::string b) { std::string r = b; std::reverse(r.begin(), r.end()); return r == b; }
    int parity_even(std::string b) { return count_ones(b) % 2; }
    int parity_odd(std::string b) { return (count_ones(b) % 2 == 0) ? 1 : 0; }
    std::string repeat(std::string b, int n) { std::string r; for(int i=0; i<n; ++i) r += b; return r; }
    std::string mask(std::string b, std::string m) { return b_and(b, m); }
    std::string slice(std::string b, int s, int l) { return b.substr(s, l); }
    std::string set_range(std::string b, int s, int e, char v) { for(int i=s; i<=e && i<(int)b.size(); ++i) b[i] = v; return b; }
    bool has_pattern(std::string b, std::string p) { return b.find(p) != std::string::npos; }
    int count_pattern(std::string b, std::string p) { int c=0; size_t pos = b.find(p); while(pos != std::string::npos){ c++; pos = b.find(p, pos+1); } return c; }
    std::string replace_pattern(std::string b, std::string p, std::string r) { size_t pos = b.find(p); while(pos != std::string::npos){ b.replace(pos, p.size(), r); pos = b.find(p, pos+r.size()); } return b; }
    std::vector<std::string> split(std::string b, int n) { std::vector<std::string> v; for(size_t i=0; i<b.size(); i+=n) v.push_back(b.substr(i, std::min((int)n, (int)(b.size()-i)))); return v; }
    std::string join(std::vector<std::string> v) { std::string s; for(const auto& x : v) s += x; return s; }
    std::string format_space(std::string b, int n) { std::string s; for(int i=0; i<(int)b.size(); ++i) { s += b[i]; if((i+1)%n==0 && i!=(int)b.size()-1) s += " "; } return s; }
    std::string xor_with_key(std::string d, std::string k) { std::string r; if(k.empty()) return d; for(size_t i=0; i<d.size(); ++i) r += (d[i] == k[i % k.size()] ? '0' : '1'); return r; }
    std::string interleave(std::string x, std::string y) { std::string r; size_t n=std::max(x.size(), y.size()); for(size_t i=0; i<n; ++i) { if(i<x.size()) r+=x[i]; if(i<y.size()) r+=y[i]; } return r; }
    std::string deinterleave_even(std::string b) { std::string r; for(size_t i=0; i<b.size(); i+=2) r += b[i]; return r; }
    std::string deinterleave_odd(std::string b) { std::string r; for(size_t i=1; i<b.size(); i+=2) r += b[i]; return r; }
    std::string invert_range(std::string b, int s, int e) { for(int i=s; i<=e && i<(int)b.size(); ++i) b[i] = (b[i]=='0'?'1':'0'); return b; }
    std::string bit_duplicate(std::string b) { std::string r; for(char c : b) { r += c; r += c; } return r; }
    std::string bit_reduce(std::string b) { std::string r; for(size_t i=0; i<b.size(); i+=2) r += b[i]; return r; }
    std::string bit_sync(std::string b) { return b + (parity_even(b) == 0 ? "0" : "1"); }
    std::string get_msb(std::string b) { return b.empty() ? "" : std::string(1, b[0]); }
    std::string get_lsb(std::string b) { return b.empty() ? "" : std::string(1, b.back()); }
    std::string clear_range(std::string b, int s, int e) { return set_range(b, s, e, '0'); }
    std::string fill_range(std::string b, int s, int e) { return set_range(b, s, e, '1'); }
    std::string swap_bits(std::string b, int i, int j) { if(i<(int)b.size() && j<(int)b.size()) std::swap(b[b.size()-1-i], b[b.size()-1-j]); return b; }
    std::string isolate_l(std::string b, int n) { return b.substr(0, std::min((int)n, (int)b.size())); }
    std::string isolate_r(std::string b, int n) { return b.substr(std::max(0, (int)b.size()-n)); }
    std::string concat(std::string x, std::string y) { return x + y; }
    std::string expand(std::string b, int n) { std::string r; for(char c : b) r += std::string(n, c); return r; }
    std::string reflect(std::string b) { std::string r = b; std::reverse(r.begin(), r.end()); return b + r; }
    bool is_subset(std::string sub, std::string super) { return super.find(sub) != std::string::npos; }
    std::string extract_ones(std::string b) { std::string r; for(char c : b) if(c=='1') r+=c; return r; }
    std::string extract_zeros(std::string b) { std::string r; for(char c : b) if(c=='0') r+=c; return r; }
    std::string stretch(std::string b, int n) { std::string r; for(char c : b) r += (c == '1' ? std::string(n, '1') : std::string(n, '0')); return r; }
    std::string merge(std::string x, std::string y) { return b_or(x, y); }
    std::string filter(std::string b, std::string m) { return b_and(b, m); }
    std::string remove_bit(std::string b, int i) { if(i<(int)b.size()) b.erase(b.size()-1-i, 1); return b; }
    std::string insert_bit(std::string b, int i, char v) { b.insert(std::max(0, (int)(b.size()-i)), 1, v); return b; }
    std::string bit_mask_l(int n, int total) { return ones(n) + zeros(total-n); }
    std::string bit_mask_r(int n, int total) { return zeros(total-n) + ones(n); }
    std::string bit_swap_neighbors(std::string b) { for(size_t i=0; i+1<b.size(); i+=2) std::swap(b[i], b[i+1]); return b; }
    std::string spread_bits(std::string b, int n) { std::string r; for(char c : b) { r += c; r += std::string(n, '0'); } return r; }
    std::string clean_binary(std::string b) { b.erase(std::remove_if(b.begin(), b.end(), [](char c){ return c!='0' && c!='1'; }), b.end()); return b; }
    std::string resize(std::string b, int n) { if((int)b.size() > n) return b.substr(b.size()-n); return pad_l(b, n); }
    bool compare_weight(std::string x, std::string y) { return count_ones(x) == count_ones(y); }
    std::string unique_pattern(int n) { std::string s = "1"; while((int)s.size() < n) s += (s.back() == '1' ? "0" : "1"); return s.substr(0, n); }
    std::string bit_fill(int n, char v) { return std::string(n, v); }
    std::string bit_step(int n, int s) { std::string r; for(int i=0; i<n; ++i) r += (i % s == 0 ? "1" : "0"); return r; }
    std::string bit_mod(std::string b, int m) { std::string r; for(int i=0; i<(int)b.size(); ++i) r += (i % m == 0 ? b[i] : '0'); return r; }
    std::string lcg(int n, int s) { return generate(n, s); }
};