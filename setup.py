import setuptools

with open("README.md", "r") as fh:
    long_description = fh.read()

setuptools.setup(
    name="fake_consumer",
    version="1.0.0",
    author="ChenPu",
    author_email="superchenpu@me.com",
    description="a tensorflow tool to eliminate lazy behavior",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/kor01/fake_consumer",
    packages=setuptools.find_packages(),
    package_data={'fake_consumer': ['python/_fake_consumer_ops.so']},
    classifiers=[
        "Programming Language :: Python :: 3",
        "Operating System :: Linux",
    ],
)
