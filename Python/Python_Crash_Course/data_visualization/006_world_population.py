import os
import json
import pygal

from pygal.style import LightColorizedStyle, RotateStyle
from pygal.maps.world import COUNTRIES
from pygal.maps.world import World

from country_codes import get_country_code

# File directory
current_directory = os.path.dirname(os.path.abspath(__file__))

# File path
filename = current_directory + "/../Data_Files/population_data.json"

""" Extracting Relevant Data """
import json

# Load the data into a list
with open(filename) as f:
    pop_data = json.load(f)

print(pop_data[0])
print()

# Print the 2010 population for each country
cc_populations = {}

for pop_dict in pop_data:
    if pop_dict['Year'] == '2010':
        country_name = pop_dict['Country Name']
        population = int(float(pop_dict['Value']))
        code = get_country_code(country_name)
        
        if code:
            print(code + ": "+ str(population))
            cc_populations[code] = population
        else:
            print('ERROR - ' + country_name)

""" Obtaining Two-Digit Country Codes """
for country_code in sorted(COUNTRIES.keys()):
    print(country_code, COUNTRIES[country_code])

""" Building a World Map """
wm = World()
wm.title = 'North, Central, and South America'

wm.add('North America', ['ca', 'mx', 'us'])
wm.add('Central America', ['bz', 'cr', 'gt', 'hn', 'ni', 'pa', 'sv'])
wm.add('South America', ['ar', 'bo', 'br', 'cl', 'co', 'ec', 'gf',
                         'gy', 'pe', 'py', 'sr', 'uy', 've'])

wm.render_to_file('americas.svg')

""" Plotting Numerical Data on a World Map """
wm = World()
wm.title = 'Populations of Countries in North America'
wm.add('North America', {'ca': 34126000, 'us': 309349000, 'mx': 113423000})
wm.render_to_file('north_america_populations.svg')

""" Plotting a Complete Population Map """

# Group the countries into 3 population levels.
cc_pops_1, cc_pops_2, cc_pops_3 = {}, {}, {}

for cc, pop in cc_populations.items():
    if pop < 10000000:
        cc_pops_1[cc] = pop
    elif pop < 1000000000:
        cc_pops_2[cc] = pop
    else:
        cc_pops_3[cc] = pop

# See how many countries are in each level.
print(len(cc_pops_1), len(cc_pops_2), len(cc_pops_3))

# Build the World Map
wm_style = RotateStyle('#FF3333')
wm = World(style=wm_style, base_style=LightColorizedStyle)
wm.title = 'World Population in 2010, by Country'
wm.add('>1bn', cc_pops_3)
wm.add('10m-1bn', cc_pops_2)
wm.add('0-10m', cc_pops_1)
wm.render_to_file('world_population.svg')
