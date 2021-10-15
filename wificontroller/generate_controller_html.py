# Converts html file into a String in a .h file that can be used by Arduino
# To run: `python3 generate_controller_html.py`

with open("controller.html") as f:
    html = f.read()
    # For each line in html, surround it with quotes and add a newline character
    html = "\n".join(['"{}\\n"\\'.format(line) for line in html.splitlines()])

    # Write to file
    with open("controller_html.h", "w") as f:
        f.write('String html = \\\n{}\n;'.format(html))
