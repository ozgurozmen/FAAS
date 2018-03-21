/*
 *  Copyright 2017 Zhenfei Zhang @ onboard security
 *
 *  This file is part of pqNTRUSign signature scheme with bimodal
 *  Gaussian sampler (Gaussian-pqNTRUSign).
 *
 *  This software is released under GPL:
 *  you can redistribute it and/or modify it under the terms of the
 *  GNU General Public License as published by the Free Software
 *  Foundation, either version 2 of the License, or (at your option)
 *  any later version.
 *
 *  You should have received a copy of the GNU General Public License.
 *  If not, see <http://www.gnu.org/licenses/>.
*/

#include <string.h>
//#include "poly/NTT.h"
#include "param.h"

/*
 * todo: finalize parameters for rejection sampling
 */


/*
 * NTT pre-computed params for x^512+1 mod 2^16+1
 */
static int64_t roots512[512]  = {
    431, 862, 911, 1007, 1065, 1089, 1111, 1497, 1707, 1724, 1822, 2014, 2130, 2178, 2222, 2229, 2383, 2407, 2623, 2773, 2994, 3349, 3414, 3448, 3644, 4028, 4123, 4153, 4159, 4245, 4260, 4356, 4444, 4458, 4766, 4814, 4995, 5015, 5246, 5363, 5546, 5567, 5791, 5851, 5988, 6698, 6725, 6828, 6896, 7233, 7288, 7673, 8005, 8056, 8059, 8246, 8306, 8318, 8331, 8490, 8493, 8520, 8712, 8819, 8888, 8916, 9379, 9427, 9495, 9532, 9579, 9628, 9879, 9990, 10030, 10369, 10423, 10492, 10719, 10726, 10827, 10913, 11019, 11092, 11095, 11134, 11299, 11487, 11557, 11582, 11699, 11702, 11737, 11953, 11976, 12819, 13396, 13450, 13495, 13656, 13792, 14261, 14383, 14466, 14576, 14703, 15323, 15346, 15547, 15691, 15827, 16010, 16112, 16118, 16492, 16612, 16636, 16662, 16811, 16980, 16986, 17040, 17415, 17424, 17633, 17638, 17725, 17776, 17832, 17847, 18399, 18467, 18589, 18729, 18741, 18758, 18779, 18854, 18990, 19064, 19091, 19139, 19158, 19209, 19256, 19309, 19589, 19758, 19980, 20060, 20215, 20271, 20307, 20341, 20587, 20738, 20846, 20984, 21001, 21079, 21157, 21169, 21438, 21452, 21461, 21531, 21654, 21767, 21826, 21885, 22003, 22038, 22184, 22190, 22229, 22268, 22475, 22598, 22615, 22633, 22661, 22974, 23114, 23164, 23199, 23223, 23379, 23398, 23404, 23474, 23535, 23569, 23845, 23906, 23952, 24061, 24363, 24855, 24923, 24995, 25107, 25417, 25577, 25638, 26021, 26359, 26792, 26900, 26919, 26990, 27025, 27119, 27221, 27259, 27312, 27355, 27409, 27557, 27584, 27829, 27979, 28021, 28055, 28079, 28359, 28522, 28603, 28739, 28766, 28932, 29152, 29406, 29843, 29873, 29985, 30087, 30261, 30271, 30646, 30689, 30692, 30707, 31094, 31382, 31457, 31565, 31577, 31654, 31915, 32020, 32213, 32224, 32236, 32265, 32313, 32553, 32984, 33224, 33272, 33301, 33313, 33324, 33517, 33622, 33883, 33960, 33972, 34080, 34155, 34443, 34830, 34845, 34848, 34891, 35266, 35276, 35450, 35552, 35664, 35694, 36131, 36385, 36605, 36771, 36798, 36934, 37015, 37178, 37458, 37482, 37516, 37558, 37708, 37953, 37980, 38128, 38182, 38225, 38278, 38316, 38418, 38512, 38547, 38618, 38637, 38745, 39178, 39516, 39899, 39960, 40120, 40430, 40542, 40614, 40682, 41174, 41476, 41585, 41631, 41692, 41968, 42002, 42063, 42133, 42139, 42158, 42314, 42338, 42373, 42423, 42563, 42876, 42904, 42922, 42939, 43062, 43269, 43308, 43347, 43353, 43499, 43534, 43652, 43711, 43770, 43883, 44006, 44076, 44085, 44099, 44368, 44380, 44458, 44536, 44553, 44691, 44799, 44950, 45196, 45230, 45266, 45322, 45477, 45557, 45779, 45948, 46228, 46281, 46328, 46379, 46398, 46446, 46473, 46547, 46683, 46758, 46779, 46796, 46808, 46948, 47070, 47138, 47690, 47705, 47761, 47812, 47899, 47904, 48113, 48122, 48497, 48551, 48557, 48726, 48875, 48901, 48925, 49045, 49419, 49425, 49527, 49710, 49846, 49990, 50191, 50214, 50834, 50961, 51071, 51154, 51276, 51745, 51881, 52042, 52087, 52141, 52718, 53561, 53584, 53800, 53835, 53838, 53955, 53980, 54050, 54238, 54403, 54442, 54445, 54518, 54624, 54710, 54811, 54818, 55045, 55114, 55168, 55507, 55547, 55658, 55909, 55958, 56005, 56042, 56110, 56158, 56621, 56649, 56718, 56825, 57017, 57044, 57047, 57206, 57219, 57231, 57291, 57478, 57481, 57532, 57864, 58249, 58304, 58641, 58709, 58812, 58839, 59549, 59686, 59746, 59970, 59991, 60174, 60291, 60522, 60542, 60723, 60771, 61079, 61093, 61181, 61277, 61292, 61378, 61384, 61414, 61509, 61893, 62089, 62123, 62188, 62543, 62764, 62914, 63130, 63154, 63308, 63315, 63359, 63407, 63523, 63715, 63813, 63830, 64040, 64426, 64448, 64472, 64530, 64626, 64675, 65106
};


static int64_t invntt512[512] =
{
    55045, 60291, 46473, 19980, 20738, 11976, 27312, 8712, 17776, 62914, 56005, 9990, 10369, 5988, 13656, 20846, 58249, 40542, 63813, 9879, 4356, 57044, 8888, 31457, 60771, 4995, 28739, 22661, 57532, 14466, 37953, 2994, 6828, 10423, 61893, 20271, 4028, 21654, 64675, 11487, 37708, 16811, 37516, 45196, 2178, 28522, 22190, 4444, 48497, 8490, 63154, 15323, 61378, 35266, 30707, 47138, 44099, 28766, 21885, 7233, 62188, 51745, 1497, 42158, 3414, 37980, 23164, 22184, 35664, 63715, 42063, 42904, 2773, 2014, 10827, 2130, 4458, 65106, 48925, 38512, 10030, 32213, 38618, 18854, 13450, 41174, 23404, 5363, 42922, 18758, 38278, 22598, 46379, 12819, 1089, 11953, 14261, 11095, 24923, 2222, 57017, 13396, 16636, 4245, 31577, 42314, 7673, 40430, 33972, 26021, 47690, 30689, 17633, 48122, 23569, 54818, 14383, 43711, 5567, 36385, 31094, 58641, 49419, 33517, 16112, 21079, 45948, 1707, 18990, 49710, 57291, 22003, 37558, 27119, 23199, 11582, 37178, 11092, 17832, 64626, 40120, 23398, 53800, 28079, 21452, 22038, 47812, 34155, 1007, 38182, 30692, 4814, 38547, 59686, 22268, 1065, 2229, 32553, 22475, 17638, 29406, 28055, 57231, 19256, 23114, 23535, 5015, 28603, 48875, 8331, 18467, 19309, 9427, 6725, 30261, 20587, 21001, 11702, 53980, 55909, 4153, 35450, 21461, 9379, 18741, 50834, 56718, 19139, 11299, 55958, 21531, 16492, 31654, 39178, 33313, 32236, 54403, 35694, 13495, 63130, 50191, 46446, 32265, 38745, 15691, 41631, 39899, 38316, 54518, 45230, 54811, 18729, 38637, 53838, 1111, 45477, 33224, 56621, 61277, 59991, 46948, 59746, 21169, 19209, 46758, 6698, 21767, 4123, 8318, 34891, 48557, 21157, 40682, 56042, 31915, 42563, 22229, 57481, 36605, 16010, 20215, 8059, 16986, 45779, 3448, 49990, 14576, 23845, 29985, 48113, 10913, 41585, 24061, 25577, 38128, 20984, 44553, 27409, 39960, 41476, 23952, 54624, 17424, 35552, 41692, 50961, 15547, 62089, 19758, 48551, 57478, 45322, 49527, 28932, 8056, 43308, 22974, 33622, 9495, 24855, 44380, 16980, 30646, 57219, 61414, 43770, 58839, 18779, 46328, 44368, 5791, 18589, 5546, 4260, 8916, 32313, 20060, 64426, 11699, 26900, 46808, 10726, 20307, 11019, 27221, 25638, 23906, 49846, 26792, 33272, 19091, 15346, 2407, 52042, 29843, 11134, 33301, 32224, 26359, 33883, 49045, 44006, 9579, 54238, 46398, 8819, 14703, 46796, 56158, 44076, 30087, 61384, 9628, 11557, 53835, 44536, 44950, 35276, 58812, 56110, 46228, 47070, 57206, 16662, 36934, 60522, 42002, 42423, 46281, 8306, 37482, 36131, 47899, 43062, 32984, 63308, 64472, 43269, 5851, 26990, 60723, 34845, 27355, 64530, 31382, 17725, 43499, 44085, 37458, 11737, 42139, 25417, 911, 47705, 54445, 28359, 53955, 42338, 38418, 27979, 43534, 8246, 15827, 46547, 63830, 19589, 44458, 49425, 32020, 16118, 6896, 34443, 29152, 59970, 21826, 51154, 10719, 41968, 17415, 47904, 34848, 17847, 39516, 31565, 25107, 57864, 23223, 33960, 61292, 48901, 52141, 8520, 63315, 40614, 54442, 51276, 53584, 64448, 52718, 19158, 42939, 27259, 46779, 22615, 60174, 42133, 24363, 52087, 46683, 26919, 33324, 55507, 27025, 16612, 431, 61079, 63407, 54710, 63523, 62764, 22633, 23474, 1822, 29873, 43353, 42373, 27557, 62123, 23379, 64040, 13792, 3349, 58304, 43652, 36771, 21438, 18399, 34830, 30271, 4159, 50214, 2383, 57047, 17040, 61093, 43347, 37015, 63359, 20341, 28021, 48726, 27829, 54050, 862, 43883, 61509, 45266, 3644, 55114, 58709, 62543, 27584, 51071, 8005, 42876, 36798, 60542, 4766, 34080, 56649, 8493, 61181, 55658, 1724, 24995, 7288, 44691, 51881, 59549, 55168, 55547, 9532, 2623, 47761, 56825, 38225, 53561, 44799, 45557, 19064, 5246, 10492
};

/*
 * NTT pre-computed params for x^751-1 mod 65447
 */
static int64_t roots761[761]  =
{
    1, 58, 150, 362, 370, 503, 570, 585, 768, 801, 882, 886, 952, 1187, 1230, 1341, 1363, 1406, 1433, 1443, 1540, 1693, 1773, 1992, 2005, 2006, 2073, 2092, 2125, 2166, 2223, 2272, 2278, 2346, 2453, 2623, 2659, 2874, 3022, 3034, 3046, 3193, 3245, 3348, 3364, 3399, 3525, 3541, 3564, 3565, 3685, 3779, 3795, 3842, 4011, 4065, 4162, 4215, 4243, 4439, 4530, 4674, 4716, 4793, 4797, 4809, 5124, 5160, 5174, 5303, 5378, 5489, 5541, 5570, 5642, 5788, 5852, 5893, 5908, 5912, 6006, 6134, 6146, 6168, 6215, 6255, 6341, 6570, 6628, 6634, 6719, 7062, 7143, 7347, 7574, 7618, 7619, 7653, 7821, 7944, 8038, 8075, 8109, 8194, 8412, 8469, 8507, 8695, 8700, 8905, 8942, 9037, 9304, 9361, 9393, 9740, 9967, 9981, 9999, 10003, 10027, 10080, 10086, 10110, 10221, 10247, 10334, 10349, 10371, 10397, 10429, 10456, 10739, 10797, 10880, 10922, 11024, 11129, 11174, 11219, 11237, 11278, 11380, 11429, 11691, 11740, 11749, 11847, 11906, 11991, 12067, 12097, 12148, 12181, 12193, 12237, 12261, 12331, 12449, 12495, 12507, 12627, 12628, 12661, 12728, 13231, 13255, 13395, 13426, 13476, 13537, 13547, 13554, 13565, 13607, 13796, 14003, 14054, 14102, 14137, 14394, 14421, 14465, 14559, 14654, 14715, 14777, 14785, 14804, 14841, 14990, 15265, 15429, 15447, 15508, 15661, 15838, 15859, 15992, 16007, 16017, 16056, 16101, 16206, 16228, 16248, 16417, 16438, 16441, 16707, 16914, 16981, 16987, 17123, 17134, 17209, 17214, 17389, 17425, 17455, 17600, 17667, 18003, 18048, 18247, 18307, 18415, 18609, 18694, 18831, 18971, 19064, 19362, 19387, 19517, 19608, 19638, 20053, 20109, 20124, 20176, 20180, 20271, 20413, 20549, 20659, 20679, 20727, 20821, 20918, 20996, 21039, 21113, 21166, 21213, 21218, 21240, 21313, 21336, 21460, 21501, 21612, 21723, 21807, 21933, 21992, 22063, 22120, 22248, 22303, 22372, 22500, 22546, 22604, 22758, 22841, 22906, 23302, 23328, 23355, 23501, 23608, 23617, 23690, 23705, 23769, 23823, 23843, 23873, 24021, 24099, 24120, 24266, 24298, 24573, 24575, 24632, 24665, 24840, 24864, 24922, 24938, 24939, 24966, 25005, 25030, 25253, 25494, 25623, 25841, 25978, 26126, 26145, 26187, 26209, 26246, 26405, 26450, 26495, 26609, 26810, 26857, 26944, 26972, 26989, 27313, 27628, 27654, 27689, 27758, 27869, 27938, 28174, 28220, 28280, 28382, 28537, 28621, 28819, 28905, 28917, 28945, 29174, 29233, 29572, 29667, 29763, 29767, 29768, 29820, 30088, 30101, 30189, 30217, 30251, 30509, 30685, 30821, 31119, 31212, 31318, 31429, 31446, 31581, 31696, 31769, 32043, 32170, 32360, 32467, 32549, 32552, 32557, 32656, 32747, 33041, 33060, 33073, 33139, 33175, 33204, 33235, 33244, 33268, 33333, 33344, 33444, 33839, 33904, 33930, 34529, 34559, 34563, 34582, 34598, 34659, 34718, 34834, 34892, 34897, 34970, 35005, 35063, 35198, 35234, 35277, 35327, 35351, 35389, 35404, 35555, 35798, 35928, 35989, 36060, 36078, 36161, 36190, 36283, 36297, 36351, 36431, 37012, 37100, 37146, 37175, 37203, 37320, 37387, 37492, 37708, 37833, 37986, 38041, 38304, 38349, 38418, 38818, 38962, 39095, 39112, 39236, 39272, 39312, 39429, 39467, 39517, 39722, 39925, 40122, 40315, 40472, 40494, 40539, 40543, 40680, 40715, 40840, 40898, 41008, 41011, 41012, 41244, 41344, 41734, 41789, 41860, 42017, 42216, 42312, 42346, 42432, 42576, 42628, 42635, 42708, 42981, 43047, 43227, 43244, 43267, 43274, 43298, 43437, 43482, 43534, 43940, 44071, 44084, 44103, 44161, 44236, 44364, 44382, 44392, 44453, 44544, 44611, 44612, 44819, 44845, 44958, 45046, 45055, 45078, 45115, 45379, 45416, 45650, 45674, 45774, 45786, 45840, 45841, 45911, 46181, 46224, 46300, 46458, 46471, 46508, 46610, 46627, 46630, 46675, 46812, 46891, 47037, 47069, 47093, 47095, 47141, 47153, 47156, 47256, 47427, 47430, 47481, 47499, 47524, 47625, 47869, 47882, 48067, 48129, 48183, 48577, 48653, 48683, 48752, 48822, 48873, 49162, 49220, 49333, 49340, 49375, 49488, 49529, 49582, 49676, 49699, 49753, 50081, 50089, 50114, 50136, 50234, 50369, 50475, 50490, 50570, 50843, 50847, 50851, 50885, 50901, 50963, 50964, 51054, 51156, 51192, 51291, 51388, 51547, 51711, 51721, 51978, 52012, 52028, 52308, 52392, 52425, 52578, 52598, 52721, 52724, 52748, 52803, 52930, 52936, 52941, 52976, 53166, 53392, 53533, 53606, 53723, 53825, 53874, 54083, 54118, 54123, 54252, 54269, 54300, 54510, 54593, 54703, 54787, 54898, 54960, 54967, 55131, 55215, 55216, 55276, 55322, 55326, 55493, 55494, 55500, 55525, 55790, 55813, 55889, 55917, 56083, 56142, 56183, 56366, 56459, 56574, 56598, 56668, 56731, 56799, 56962, 56993, 57118, 57189, 57316, 57471, 57496, 57521, 57527, 57537, 57609, 57803, 57841, 57990, 57999, 58007, 58108, 58361, 58461, 58505, 58560, 58683, 58791, 58944, 59058, 59069, 59095, 59339, 59378, 59442, 59496, 59590, 59612, 59726, 60016, 60081, 60164, 60181, 60235, 60324, 60326, 60377, 60507, 60551, 60616, 60617, 60618, 60714, 60728, 60757, 60805, 60846, 60849, 60864, 60911, 60936, 60968, 61014, 61064, 61072, 61121, 61272, 61317, 61412, 61421, 61507, 61532, 61534, 61535, 61665, 61679, 61684, 61691, 61846, 61881, 62046, 62091, 62325, 62418, 62467, 62469, 62623, 62723, 62804, 62835, 63112, 63119, 63125, 63290, 63364, 63470, 63487, 63667, 63868, 63888, 64147, 64175, 64216, 64218, 64237, 64480, 64491, 64530, 64552, 64568, 64629, 64699, 64754, 64796, 64850, 65079, 65080, 65101, 65229
};

static int64_t invntt761[761] =
{
    1, 5642, 29233, 45379, 57841, 19517, 55917, 64552, 63487, 45674, 20109, 61532, 60016, 43227, 3565, 42216, 11380, 1443, 35989, 1406, 10922, 61272, 48873, 6341, 60616, 19608, 16417, 20679, 56731, 14715, 44544, 53723, 10429, 48067, 13607, 33235, 47430, 60551, 16914, 26209, 14804, 58560, 40680, 48577, 24922, 31212, 61121, 10110, 29767, 1230, 50475, 24298, 54703, 30509, 10247, 39236, 61846, 47156, 60326, 8109, 12237, 59496, 8507, 17123, 12661, 31696, 45841, 46891, 47093, 50847, 52803, 53166, 20918, 32747, 58, 62835, 37320, 21501, 9981, 18609, 61535, 60507, 8700, 26495, 21240, 39467, 1992, 24575, 12728, 32467, 63119, 44382, 43274, 34563, 52425, 55215, 12507, 24099, 38418, 29667, 49529, 49375, 4439, 16206, 10371, 54118, 4716, 44236, 6146, 37203, 28537, 36283, 64216, 64629, 54898, 38818, 22063, 5908, 11906, 38962, 21213, 43482, 43534, 3541, 31318, 4011, 39272, 34529, 8412, 33268, 2278, 26145, 54593, 58361, 57609, 1540, 60846, 25005, 26187, 42346, 33204, 39722, 1363, 12495, 51547, 23843, 56668, 35389, 9999, 24632, 47869, 48129, 63125, 16441, 44084, 4530, 26972, 21039, 18048, 11429, 7619, 65079, 49220, 4797, 6628, 15992, 37387, 60864, 53392, 57118, 28220, 14102, 17214, 18247, 2453, 45774, 61507, 59612, 13547, 43244, 55494, 35063, 18831, 35351, 60235, 2166, 63888, 61317, 3046, 36161, 15661, 22303, 28382, 20659, 45650, 14990, 39112, 24864, 13231, 61665, 57189, 57527, 25978, 8194, 65080, 23302, 2073, 30685, 12181, 29572, 3022, 58683, 62804, 4793, 27628, 54787, 13554, 20053, 57999, 37146, 32043, 33344, 64480, 12449, 13565, 24939, 59590, 5912, 52721, 14465, 56574, 54300, 31581, 23705, 503, 2006, 62091, 17389, 882, 33839, 42017, 21460, 62467, 55322, 37012, 15447, 2092, 27313, 52748, 5541, 65101, 12331, 49582, 46508, 10027, 39312, 6215, 64796, 22604, 20180, 5893, 34598, 52028, 27689, 28819, 39095, 9967, 35555, 37492, 15265, 51291, 26810, 43940, 21336, 60377, 43298, 50901, 16248, 52724, 48653, 33073, 47153, 50369, 24966, 19387, 51721, 41244, 11740, 36297, 53606, 7653, 37708, 62046, 3779, 45786, 6570, 11991, 60968, 34718, 15859, 3364, 50963, 18307, 23690, 11129, 56366, 50234, 41344, 54967, 27938, 16101, 52308, 10456, 11174, 3034, 43047, 45078, 28621, 6168, 28905, 22500, 46610, 51711, 12261, 39517, 20727, 17134, 62723, 21807, 39429, 46458, 25841, 64850, 13537, 50490, 15429, 8942, 26450, 21933, 26609, 34834, 60805, 33060, 150, 16707, 7944, 41008, 3564, 64218, 58944, 61064, 46181, 30251, 50851, 30189, 3842, 16438, 52392, 41789, 3399, 10221, 47499, 32557, 19362, 4809, 37986, 17600, 42981, 34659, 6634, 44819, 55525, 31446, 51388, 5570, 52976, 29174, 23501, 51192, 59069, 11237, 2623, 52936, 10397, 59058, 17667, 37833, 20124, 64754, 55276, 10349, 44392, 7347, 61679, 21612, 32360, 24840, 28917, 49753, 50843, 63364, 58505, 14421, 44103, 60181, 36190, 51156, 14559, 11847, 53825, 22120, 60849, 46300, 1433, 46675, 64491, 14841, 35277, 9037, 23873, 54252, 47256, 20549, 60714, 17455, 45055, 8905, 5852, 13255, 22248, 24120, 33444, 31769, 53533, 49333, 63667, 7821, 9740, 10003, 21992, 15838, 4065, 10334, 21218, 27758, 6255, 26989, 11278, 56459, 57521, 58007, 57803, 47625, 40840, 47427, 3245, 52012, 40539, 47481, 29763, 61534, 59442, 23823, 25494, 62469, 31119, 50089, 20176, 1341, 56799, 11219, 60081, 45416, 48683, 54083, 55500, 32170, 26246, 1187, 14137, 49699, 7143, 22841, 46812, 10080, 10086, 22546, 47882, 12193, 35198, 63470, 8695, 55889, 7062, 34559, 49676, 2223, 55493, 51054, 32549, 63290, 46224, 64568, 37175, 26405, 62418, 362, 42576, 15508, 801, 13796, 24573, 60617, 5124, 63112, 30101, 44958, 35928, 27869, 54269, 21166, 26857, 60728, 57990, 36060, 43437, 5160, 55326, 62623, 5174, 48183, 50964, 23608, 4215, 36431, 40543, 2659, 40898, 31429, 61014, 40494, 12067, 44071, 2346, 12097, 47095, 3348, 23355, 42628, 61421, 60164, 1773, 60757, 12628, 38304, 55813, 8075, 64147, 8038, 21113, 44453, 43267, 34892, 62325, 41860, 54123, 65229, 25253, 23617, 3685, 28280, 58791, 34897, 5303, 30217, 53874, 22906, 24938, 47141, 44612, 35327, 33139, 22372, 32656, 11691, 26944, 23769, 52930, 40715, 21723, 26126, 30821, 7574, 56598, 63868, 18694, 23328, 20821, 5378, 51978, 33244, 55216, 33041, 5489, 13426, 38041, 24021, 2272, 35404, 50885, 42635, 8469, 50114, 36351, 46471, 19064, 64699, 10739, 3795, 17209, 9393, 55131, 25623, 54960, 7618, 52941, 33930, 20413, 47037, 44611, 14394, 42708, 32552, 56962, 49340, 44364, 570, 60911, 61881, 57471, 25030, 39925, 18971, 52578, 11749, 2125, 42312, 55790, 59726, 13476, 16017, 59378, 56183, 64237, 40122, 16056, 58108, 10880, 40472, 370, 46630, 17425, 40315, 57537, 10797, 61072, 35005, 3193, 16981, 50570, 29820, 33333, 33175, 64530, 60936, 57316, 41012, 4674, 18415, 14054, 56993, 952, 42432, 48822, 35234, 14654, 60618, 4243, 22758, 6134, 2874, 2005, 45840, 60324, 37100, 46627, 49162, 28945, 11024, 35798, 13395, 56083, 59339, 24665, 47524, 30088, 58461, 3525, 1693, 14785, 61684, 48752, 14003, 886, 41011, 6006, 16007, 34582, 61412, 64175, 4162, 56142, 24266, 19638, 50081, 45115, 20271, 41734, 47069, 27654, 16987, 5788, 45911, 6719, 12148, 44845, 34970, 44161, 768, 38349, 52598, 14777, 49488, 61691, 9304, 29768, 57496, 18003, 36078, 59095, 585, 45046, 9361, 54510, 33904, 21313, 28174, 12627, 16228, 20996, 50136
};

static PQ_PARAM_SET pqParamSets[] = {
    {
        Gaussian_512_107,    /* parameter set id */
        "gaussian-512-107",  /* human readable name */
        {0xff, 0xff, 0xf9},  /* OID */
        9,                   /* bitlength of N */
        17,                  /* bitlength of q */
        512,                 /* ring degree (N)*/
        2,                   /* message space prime */
        65537,               /* ring modulus */
        215,                 /* max l2 norm of f*a convolution (Gaussian only)*/
        40,                  /* max norm of g*a convolution */
        0,                   /* (q/2 - B_s)/p (uniform only)*/
        (1<<15)-39,          /* q/2 - B_t */
        7.38905609893065,    /* rejection rate on s side: e^2 (Gaussian only)*/
        77,                  /* Product form +1/-1 counts */
        512,                 /* # Polynomial coefficients for Karatsuba */
        107,                 /* std dev */
        /* NTT param */
        roots512,
        invntt512,
        65409,
    },
    {
        Gaussian_761_107,    /* parameter set id */
        "gaussian-761-107",  /* human readable name */
        {0xff, 0xff, 0xf9},  /* OID */
        9,                   /* bitlength of N */
        17,                  /* bitlength of q */
        761,                 /* ring degree */
        2,                   /* message space prime */
        65447,               /* ring modulus */
        400,                 /* max l2 norm of f*a convolution (Gaussian only)*/
        100,                 /* max norm of g*a convolution */
        0,                   /* (q/2 - B_s)/p (uniform only)*/
        32723-1,             /* q/2 - B_t */
        7.38905609893065,    /* rejection rate on s side: e^2 (Gaussian only)*/
        77,                  /* Product form +1/-1 counts */
        768,                 /* # Polynomial coefficients for Karatsuba */
        107,                 /* std dev */
        /* NTT param */
        roots761,
        invntt761,
        65361,
    },
    {
        uniform_512_107,     /* parameter set id */
        "uniform-512-107",   /* human readable name */
        {0xff, 0xff, 0xf9},  /* OID */
        9,                   /* bitlength of N */
        17,                  /* bitlength of q */
        512,                 /* ring degree */
        2,                   /* message space prime */
        65537,               /* ring modulus */
        0,                   /* max l2 norm of f*a convolution (Gaussian only)*/
        40,                  /* max norm of g*a convolution */
        16384-20,            /* (q/2 - B_s)/p (uniform only)*/
        (1<<15)-39,          /* q/2 - B_t */
        0,                   /* rejection rate on s side: e^2 (Gaussian only)*/
        77,                  /* Product form +1/-1 counts */
        512,                 /* # Polynomial coefficients for Karatsuba */
        0,                   /* std dev (Gaussian only)*/
        /* NTT param */
        roots512,
        invntt512,
        65409,
    },
    {
        uniform_761_107,     /* parameter set id */
        "uniform-761-197",   /* human readable name */
        {0xff, 0xff, 0xf9},  /* OID */
        9,                   /* bitlength of N */
        17,                  /* bitlength of q */
        761,                 /* ring degree */
        2,                   /* message space prime */
        65447,               /* ring modulus */
        0,                   /* max l2 norm of f*a convolution (Gaussian only)*/
        40,                  /* max norm of g*a convolution */
        16362-20,            /* (q/2 - B_s)/p (uniform only)*/
        32724-39,            /* q/2 - B_t */
        0,                   /* rejection rate on s side: e^2 (Gaussian only)*/
        77,                  /* Product form +1/-1 counts */
        768,                 /* # Polynomial coefficients for Karatsuba */
        0,                   /* std dev (Gaussian only)*/
        /* NTT param */
        roots761,
        invntt761,
        65361,
    },

};

static int numParamSets = sizeof(pqParamSets)/sizeof(PQ_PARAM_SET);

PQ_PARAM_SET *
pq_get_param_set_by_id(PQ_PARAM_SET_ID id)
{
    int i;

    for(i=0; i<numParamSets; i++)
    {
        if(pqParamSets[i].id == id)
        {
            return (pqParamSets + i);
        }
    }
    return NULL;
}