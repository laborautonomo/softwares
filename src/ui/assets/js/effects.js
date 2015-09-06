$(document).ready(function() {

    var effect = {
        heading: {
            position: null,
            height: null,
            offset: null,
            heading: null,
            setUp: function(heading, offset) {
                this.position = heading.position().top;
                this.height = heading.height();
                this.offset = offset;
                this.heading = heading;
            },
            getViewPort: function() {

                var minimum = this.position + this.offset;
                var maximum = this.height + minimum;

                return {
                    minimum: minimum,
                    maximum: maximum
                };

            },
            isInViewPort: function(position) {

                var viewPort = this.getViewPort();
                if ((position < viewPort.minimum) || (position > viewPort.maximum)) {
                    return false;
                }

                return true;

            },
            resize: function(difference) {
                var height = this.heading.height();
                height += difference;

                if (height > this.height) {
                    height = this.height;
                }

                if (height < 0) {
                    height = 0;
                }

                this.heading.height(height);

            }
        },
        viewPort: {
            window: null,
            lastPosition: null,
            setUp: function(window) {
                this.window = window;
                this.lastPosition = 0;
            },
            isInViewPort: function(object) {
                var position = this.window.scrollTop();
                return object.isInViewPort(position);
            },
            getPositionDifference: function() {
                var position = this.window.scrollTop();
                return (position - this.lastPosition);
            },
            updateLastPosition: function() {
                this.lastPosition = this.window.scrollTop();
            }
        },
        setUp: function(window, heading, offset) {
            this.heading.setUp(heading, offset);
            this.viewPort.setUp(window);
        },
        resize: function() {
            var difference = this.viewPort.getPositionDifference();
            this.heading.resize(difference * -1);
        },
        scroll: function() {

            if (this.viewPort.isInViewPort(this.heading)) {
                this.resize();
            }

            this.viewPort.updateLastPosition();
        }
    };

    var offset = $('#heading').position().top * -1;
    effect.setUp($(window), $('#heading'), offset);

    $(this).bind('scroll', function(evt) {
        effect.scroll();
    });

});
