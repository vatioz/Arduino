# Automated curtains control

I decided that I want to try to build an automated curtain control system as my arduino project.

The first idea was that controlling curtains in my living room is very suitable for automation. We have quite straight forward 'rules' for when to close or open the shades:
 * In the morning, when the Sun is rising outside, we want shades open.  
 * Througout the day, we want to leave them open.  
 * In the evening, just when we turn the lights in the room on, we want the shades to close.
 * Throughout the night, we want to leave them closed.

Ok, so what are the triggers? I settled down with difference in light intensity inside versus outside.
 * In the morning, lights in the room are off, Sun is increasing light outside (meaning behind closed curtains).
 * After shades open, the light intensity inside and outside should equalize, so there is no significant difference.
 * In the evening, it is getting darker (both outside and inside) until we turn on the lights - inside has much more light intensity
 * After, shades close, diference remains the same
 * After we turn the lights off, intensity should again equalize

For this set up to work, I will need these parts:
 1. Arduino
 2. 2 photo resistors (aka light sensors)
 3. Some motor
 4. Some stuff that will connect motor to curtain chain

Wow, that sounds quite easy. Lets do this!

After some investigation online on some details I found that I will need so much more knowledge that I currently don't have. This was so frustrating that I postponed the project indefinitely.

...a year passed...

Than I saw this tweet: https://twitter.com/ThePracticalDev/status/760480121241427968  
Especially the comment: 
> "Remember that hardware project you were so excited about?"

This was so embarasing for me that I decided to start for real. And because of the lack of knowledge I talked three of my colleagues into it so I have somebody to discuss the problems with. Also we agreed we should buy some sort of starter kit, so we can learn some basics. This one was chosen: http://www.miniinthebox.com/arduino-compatible-uno-2011-component-basic-element-pack-starter-kit_p479152.html# 

The argument in favor of starter kit was that the kit would contain parts that work together and we don't have to understand all the details in advance, before we buy.  
And as we will progress, we will understand what is suitable for ourr project and what is not. And most importantly - why.

So we bought those kits, threw in some sessions to get us in speed and we started thinking about our projects.

## List of problems that gradually came
1. Buying things from China equals fun with customs in Czech Republic
2. I AM PROGRAMMER as in "electrical noob" (LED circut, BTN circut, photo resistor circut)
3. Advanced engeneering (stepper motor)
3. So much wires!
4. First actual working prototype of the project (without motor-curtain connection)
4. Power supply (battery, LED eaters, button controlled status LEDs, motor driver LEDs = need of transistor) - [very nice article here about battery life](https://hwstartup.wordpress.com/2013/04/15/how-to-run-an-arduino-clone-on-aa-batteries-for-over-a-year-part-2/), [why you can't use digital pin OUT as power supply for motor](http://forum.arduino.cc/index.php?topic=3216.0), [can you use 3,3V as input for digital pin?](https://electronics.stackexchange.com/questions/58498/3-3v-input-to-arduino-digital-pin)
5. Soldering? Ha ha ha
6. 



# Dillinger

[![N|Solid](https://cldup.com/dTxpPi9lDf.thumb.png)](https://nodesource.com/products/nsolid)

Dillinger is a cloud-enabled, mobile-ready, offline-storage, AngularJS powered HTML5 Markdown editor.

  - Type some Markdown on the left
  - See HTML in the right
  - Magic

You can also:
  - Import and save files from GitHub, Dropbox, Google Drive and One Drive
  - Drag and drop files into Dillinger
  - Export documents as Markdown, HTML and PDF

Markdown is a lightweight markup language based on the formatting conventions that people naturally use in email.  As [John Gruber] writes on the [Markdown site][df1]

> The overriding design goal for Markdown's
> formatting syntax is to make it as readable
> as possible. The idea is that a
> Markdown-formatted document should be
> publishable as-is, as plain text, without
> looking like it's been marked up with tags
> or formatting instructions.

This text you see here is *actually* written in Markdown! To get a feel for Markdown's syntax, type some text into the left window and watch the results in the right.

### Tech

Dillinger uses a number of open source projects to work properly:

* [AngularJS] - HTML enhanced for web apps!
* [Ace Editor] - awesome web-based text editor
* [markdown-it] - Markdown parser done right. Fast and easy to extend.
* [Twitter Bootstrap] - great UI boilerplate for modern web apps
* [node.js] - evented I/O for the backend
* [Express] - fast node.js network app framework [@tjholowaychuk]
* [Gulp] - the streaming build system
* [keymaster.js] - awesome keyboard handler lib by [@thomasfuchs]
* [jQuery] - duh

And of course Dillinger itself is open source with a [public repository][dill]
 on GitHub.

### Installation

Dillinger requires [Node.js](https://nodejs.org/) v4+ to run.

Download and extract the [latest pre-built release](https://github.com/joemccann/dillinger/releases).

Install the dependencies and devDependencies and start the server.

```sh
$ cd dillinger
$ npm install -d
$ node app
```

For production environments...

```sh
$ npm install --production
$ npm run predeploy
$ NODE_ENV=production node app
```

### Plugins

Dillinger is currently extended with the following plugins

* Dropbox
* Github
* Google Drive
* OneDrive

Readmes, how to use them in your own application can be found here:

* [plugins/dropbox/README.md] [PlDb]
* [plugins/github/README.md] [PlGh]
* [plugins/googledrive/README.md] [PlGd]
* [plugins/onedrive/README.md] [PlOd]

### Development

Want to contribute? Great!

Dillinger uses Gulp + Webpack for fast developing.
Make a change in your file and instantanously see your updates!

Open your favorite Terminal and run these commands.

First Tab:
```sh
$ node app
```

Second Tab:
```sh
$ gulp watch
```

(optional) Third:
```sh
$ karma start
```
#### Building for source
For production release:
```sh
$ gulp build --prod
```
Generating pre-built zip archives for distribution:
```sh
$ gulp build dist --prod
```
### Docker
Dillinger is very easy to install and deploy in a Docker container.

By default, the Docker will expose port 80, so change this within the Dockerfile if necessary. When ready, simply use the Dockerfile to build the image.

```sh
cd dillinger
npm run-script build-docker
```
This will create the dillinger image and pull in the necessary dependencies. Moreover, this uses a _hack_ to get a more optimized `npm` build by copying the dependencies over and only installing when the `package.json` itself has changed.  Look inside the `package.json` and the `Dockerfile` for more details on how this works.

Once done, run the Docker image and map the port to whatever you wish on your host. In this example, we simply map port 8000 of the host to port 80 of the Docker (or whatever port was exposed in the Dockerfile):

```sh
docker run -d -p 8000:8080 --restart="always" <youruser>/dillinger:latest
```

Verify the deployment by navigating to your server address in your preferred browser.

```sh
127.0.0.1:8000
```

#### Kubernetes + Google Cloud

See [KUBERNETES.md](https://github.com/joemccann/dillinger/blob/master/KUBERNETES.md)


#### docker-compose.yml

Change the path for the nginx conf mounting path to your full path, not mine!

### N|Solid and NGINX

More details coming soon.


### Todos

 - Write Tests
 - Rethink Github Save
 - Add Code Comments
 - Add Night Mode

License
----

MIT


**Free Software, Hell Yeah!**

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


   [dill]: <https://github.com/joemccann/dillinger>
   [git-repo-url]: <https://github.com/joemccann/dillinger.git>
   [john gruber]: <http://daringfireball.net>
   [@thomasfuchs]: <http://twitter.com/thomasfuchs>
   [df1]: <http://daringfireball.net/projects/markdown/>
   [markdown-it]: <https://github.com/markdown-it/markdown-it>
   [Ace Editor]: <http://ace.ajax.org>
   [node.js]: <http://nodejs.org>
   [Twitter Bootstrap]: <http://twitter.github.com/bootstrap/>
   [keymaster.js]: <https://github.com/madrobby/keymaster>
   [jQuery]: <http://jquery.com>
   [@tjholowaychuk]: <http://twitter.com/tjholowaychuk>
   [express]: <http://expressjs.com>
   [AngularJS]: <http://angularjs.org>
   [Gulp]: <http://gulpjs.com>

   [PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
   [PlGh]:  <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
   [PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
   [PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>

