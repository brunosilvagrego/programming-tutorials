import requests
import pygal
from pygal.style import LightColorizedStyle as LCS, LightenStyle as LS

""" Processing an API Response """
# Make an API call and store the response
url = 'https://api.github.com/search/repositories?q=language:python&sort=stars'
r = requests.get(url)
print("Status code:", r.status_code)

# Store API response in a variable
response_dict = r.json()

# Explore information about the repositories
print("Total repositories:", response_dict['total_count'])

repo_dicts = response_dict['items']
print("Repositories returned:", len(repo_dicts))

# Examine the first repository
repo_dict = repo_dicts[0]
print("\nFirst repository keys:", len(repo_dict))

for key in sorted(repo_dict.keys()):
    print(key)

print("\nSelected information about first repository:")
print('Name:', repo_dict['name'])
print('Owner:', repo_dict['owner']['login'])
print('Stars:', repo_dict['stargazers_count'])
print('Repository:', repo_dict['html_url'])
print('Created:', repo_dict['created_at'])
print('Updated:', repo_dict['updated_at'])
print('Description:', repo_dict['description'])

# Summarizing the Top Repositories #
print("\nSelected information about each repository:")

for repo_dict in repo_dicts:
    print('\nName:', repo_dict['name'])
    print('Owner:', repo_dict['owner']['login'])
    print('Stars:', repo_dict['stargazers_count'])
    print('Repository:', repo_dict['html_url'])
    print('Description:', repo_dict['description'])

""" Visualizing Repositories Using Pygal """
names, stars = [], []

for repo_dict in repo_dicts:
    names.append(repo_dict['name'])
    stars.append(repo_dict['stargazers_count'])

# Refining Pygal Chart
my_style = LS('#FF3333', base_style=LCS)
my_config = pygal.Config()
my_config.x_label_rotation = 45
my_config.show_legend = False
my_config.title_font_size = 24
my_config.label_font_size = 14
my_config.major_label_font_size = 18
my_config.truncate_label = 15
my_config.show_y_guides = False
my_config.width = 1000

# Make visualization
chart = pygal.Bar(my_config, style=my_style)
chart.title = 'Most-Starred Python Projects on GitHub'
chart.x_labels = names
chart.add('', stars)
chart.render_to_file('python_repos.svg')

""" Adding Custom Tooltips """
my_style = LS('#336600', base_style=LCS)

chart = pygal.Bar(style=my_style, x_label_rotation=45, show_legend=False)
chart.title = 'Python Projects'
chart.x_labels = ['httpie', 'django', 'flask']

plot_dicts = [{'value': 16101, 'label': 'Description of httpie.'},
              {'value': 15028, 'label': 'Description of django.'},
              {'value': 14798, 'label': 'Description of flask.'}]

chart.add('', plot_dicts)
chart.render_to_file('bar_descriptions.svg')
